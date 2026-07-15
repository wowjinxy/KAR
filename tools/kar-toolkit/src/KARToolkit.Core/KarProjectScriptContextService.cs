using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectScriptContextService
    {
        private readonly KarProject _project;

        internal KarProjectScriptContextService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectScriptTableContext> Query(KarProjectScriptTableContextQueryOptions options = null)
        {
            KarProjectScriptTableQueryOptions tableOptions = options == null ? null : options.Tables;
            List<KarProjectScriptTableContext> contexts = new List<KarProjectScriptTableContext>();

            foreach (KarProjectScriptTable table in _project.ScriptService.QueryTables(tableOptions))
            {
                KarProjectScriptTableContext context = CreateContext(table);
                if (options == null || options.Matches(context))
                    contexts.Add(context);
            }

            return contexts
                .OrderBy(context => context.Role, StringComparer.OrdinalIgnoreCase)
                .ThenBy(context => context.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectScriptTableContextSummaryContract> QueryContracts(KarProjectScriptTableContextQueryOptions options = null)
        {
            return Query(options)
                .Select(context => context.CreateContract())
                .ToList()
                .AsReadOnly();
        }

        public KarProjectScriptTableContext Get(string address)
        {
            return Query(new KarProjectScriptTableContextQueryOptions
            {
                Tables = new KarProjectScriptTableQueryOptions
                {
                    Address = address,
                },
            }).Single();
        }

        public KarProjectScriptTableContextSummaryContract GetContract(string address)
        {
            return Get(address).CreateContract();
        }

        private KarProjectScriptTableContext CreateContext(KarProjectScriptTable table)
        {
            return new KarProjectScriptTableContext(
                table,
                table.Resource.CanQueryOutput ? _project.ResourceService.GetOutput(table.Address) : null,
                _project.ResourceGraphService.QueryResourceRelationships(table.Address));
        }
    }
}
