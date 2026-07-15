using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileToolkitContextService
    {
        private readonly KarProject _project;

        internal KarProjectFileToolkitContextService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarProjectFileToolkitContext Get(string relativePath)
        {
            KarProjectFileInsight insight = _project.FileInsightService.Get(relativePath);
            return Create(insight);
        }

        public KarProjectFileToolkitContextContract GetContract(string relativePath)
        {
            return Get(relativePath).CreateContract();
        }

        private KarProjectFileToolkitContext Create(KarProjectFileInsight insight)
        {
            IReadOnlyList<KarProjectMapContext> maps = CreateMapContexts(insight);
            IReadOnlyList<KarProjectVehicleContext> vehicles = CreateVehicleContexts(insight);
            KarProjectA2DPackageContext a2dPackage = CreateA2DPackageContext(insight);

            return new KarProjectFileToolkitContext(
                _project,
                insight,
                CreateArchiveContext(insight),
                a2dPackage,
                maps,
                vehicles,
                CreateScriptTableContexts(insight, a2dPackage, maps),
                CreateResourceDetail(insight));
        }

        private KarProjectArchiveContext CreateArchiveContext(KarProjectFileInsight insight)
        {
            if (!insight.File.IsHsdArchive)
                return null;

            try
            {
                return _project.ArchiveContextService.Get(insight.RelativePath);
            }
            catch (ArgumentException)
            {
                return null;
            }
            catch (FileNotFoundException)
            {
                return null;
            }
            catch (KeyNotFoundException)
            {
                return null;
            }
            catch (InvalidOperationException)
            {
                return null;
            }
        }

        private KarProjectA2DPackageContext CreateA2DPackageContext(KarProjectFileInsight insight)
        {
            if (!insight.File.IsA2DPackage)
                return null;

            if (insight.A2DPackage != null)
                return insight.A2DPackage;

            try
            {
                return _project.A2DPackageContextService.Get(insight.RelativePath);
            }
            catch (ArgumentException)
            {
                return null;
            }
            catch (FileNotFoundException)
            {
                return null;
            }
            catch (KeyNotFoundException)
            {
                return null;
            }
            catch (InvalidOperationException)
            {
                return null;
            }
        }

        private IReadOnlyList<KarProjectMapContext> CreateMapContexts(KarProjectFileInsight insight)
        {
            List<KarProjectMapContext> contexts = new List<KarProjectMapContext>();
            foreach (KarMapBundle map in insight.Maps)
            {
                try
                {
                    AddUnique(contexts, _project.MapContextService.Get(map.Name));
                }
                catch (ArgumentException)
                {
                }
                catch (FileNotFoundException)
                {
                }
                catch (KeyNotFoundException)
                {
                }
                catch (InvalidOperationException)
                {
                }
            }

            return contexts.AsReadOnly();
        }

        private IReadOnlyList<KarProjectVehicleContext> CreateVehicleContexts(KarProjectFileInsight insight)
        {
            List<KarProjectVehicleContext> contexts = new List<KarProjectVehicleContext>();
            foreach (KarVehicleBundle vehicle in insight.Vehicles)
            {
                try
                {
                    AddUnique(contexts, _project.VehicleService.GetContext(vehicle.Name));
                }
                catch (ArgumentException)
                {
                }
                catch (FileNotFoundException)
                {
                }
                catch (KeyNotFoundException)
                {
                }
                catch (InvalidOperationException)
                {
                }
            }

            return contexts.AsReadOnly();
        }

        private IReadOnlyList<KarProjectScriptTableContext> CreateScriptTableContexts(
            KarProjectFileInsight insight,
            KarProjectA2DPackageContext a2dPackage,
            IEnumerable<KarProjectMapContext> maps)
        {
            List<KarProjectScriptTableContext> contexts = new List<KarProjectScriptTableContext>();

            if (insight.File.IsScriptTable)
                AddScriptContext(contexts, insight.RelativePath);

            if (a2dPackage != null)
            {
                foreach (KarProjectScriptTableContext context in a2dPackage.ScriptContexts)
                    AddUnique(contexts, context);
            }

            foreach (KarProjectMapContext map in maps)
            {
                foreach (KarProjectScriptTableContext context in map.Scripts.ScriptContexts)
                    AddUnique(contexts, context);
            }

            return contexts
                .OrderBy(context => context.Role, StringComparer.OrdinalIgnoreCase)
                .ThenBy(context => context.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private void AddScriptContext(List<KarProjectScriptTableContext> contexts, string address)
        {
            try
            {
                AddUnique(contexts, _project.ScriptContextService.Get(address));
            }
            catch (ArgumentException)
            {
            }
            catch (FileNotFoundException)
            {
            }
            catch (KeyNotFoundException)
            {
            }
            catch (InvalidOperationException)
            {
            }
        }

        private KarProjectResourceDetail CreateResourceDetail(KarProjectFileInsight insight)
        {
            if (insight.Resource == null)
                return null;

            try
            {
                return _project.ResourceService.GetDetail(insight.Resource.Address);
            }
            catch (ArgumentException)
            {
                return null;
            }
            catch (FileNotFoundException)
            {
                return null;
            }
            catch (KeyNotFoundException)
            {
                return null;
            }
            catch (InvalidOperationException)
            {
                return null;
            }
        }

        private static void AddUnique(List<KarProjectMapContext> contexts, KarProjectMapContext context)
        {
            if (context == null ||
                contexts.Any(existing => string.Equals(existing.MapName, context.MapName, StringComparison.OrdinalIgnoreCase)))
            {
                return;
            }

            contexts.Add(context);
        }

        private static void AddUnique(List<KarProjectVehicleContext> contexts, KarProjectVehicleContext context)
        {
            if (context == null ||
                contexts.Any(existing => string.Equals(existing.Name, context.Name, StringComparison.OrdinalIgnoreCase)))
            {
                return;
            }

            contexts.Add(context);
        }

        private static void AddUnique(List<KarProjectScriptTableContext> contexts, KarProjectScriptTableContext context)
        {
            if (context == null ||
                contexts.Any(existing => string.Equals(existing.Address, context.Address, StringComparison.OrdinalIgnoreCase)))
            {
                return;
            }

            contexts.Add(context);
        }
    }
}
