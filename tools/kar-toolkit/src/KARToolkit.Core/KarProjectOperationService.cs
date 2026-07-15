using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationService
    {
        private readonly KarProject _project;

        internal KarProjectOperationService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarProjectOperationCatalog CreateCatalog(KarProjectOperationQueryOptions options = null)
        {
            options = options ?? new KarProjectOperationQueryOptions();
            KarProjectToolkitSurface surface = options.IncludeWorkflows
                ? _project.ToolkitService.CreateSurface(options.SnapshotOptions)
                : null;
            List<KarProjectOperation> operations = new List<KarProjectOperation>();

            if (surface != null)
            {
                operations.AddRange(surface.Workflows
                    .Select(KarProjectOperation.FromWorkflow)
                    .Where(options.Matches));
            }

            if (options.IncludeResourceActions)
            {
                operations.AddRange(_project.ResourceService.QueryActionPlans(options.CreateResourceActionPlanQuery())
                    .Select(plan => KarProjectOperation.FromResourceActionPlan(plan, InferTargetDomain(plan.Resource)))
                    .Where(options.Matches));
            }

            return new KarProjectOperationCatalog(_project, surface, operations);
        }

        public IReadOnlyList<KarProjectOperation> Query(KarProjectOperationQueryOptions options = null)
        {
            return CreateCatalog(options).Operations;
        }

        private static string InferTargetDomain(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            if (resource.Category != null && string.Equals(resource.Category, "Scripts", StringComparison.OrdinalIgnoreCase))
                return "script-tables";
            if (resource.A2DEntry != null)
                return resource.A2DEntry.IsScriptTable ? "script-tables" : "a2d-packages";
            if (resource.File != null)
            {
                if (resource.File.IsScriptTable)
                    return "script-tables";
                if (resource.File.IsA2DPackage)
                    return "a2d-packages";
                if (resource.File.IsMapBundlePart)
                    return "maps";
                if (resource.File.Kind == KarFileKind.VehicleData)
                    return "vehicles";
                if (resource.File.IsHsdArchive)
                    return "archives";
            }

            return resource.IsFile ? "files" : "resources";
        }
    }
}
