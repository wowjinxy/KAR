using System;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectModWorkspaceService
    {
        private readonly KarProject _project;

        internal KarProjectModWorkspaceService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarProjectModWorkspace CreateSnapshot(KarProjectModWorkspaceOptions options = null)
        {
            KarProjectOutputInventory outputInventory = _project.OutputService.CreateInventory(options == null ? null : options.OutputFiles);
            KarProjectResourceOutputQueryOptions resourceOutputOptions = options == null ? null : options.ResourceOutputs;
            KarProjectA2DEntryOutputQueryOptions a2dOutputOptions = options == null ? null : options.A2DEntryOutputs;
            KarProjectMapOutputQueryOptions mapOutputOptions = options == null ? null : options.MapOutputs;

            return new KarProjectModWorkspace(
                _project,
                outputInventory,
                _project.ResourceService.QueryOutputs(resourceOutputOptions)
                    .Where(output => output.HasOutput),
                _project.A2DService.QueryEntryOutputs(a2dOutputOptions)
                    .Where(output => output.HasOutput),
                _project.MapService.QueryOutputs(mapOutputOptions)
                    .Where(output => output.HasOutput));
        }
    }
}
