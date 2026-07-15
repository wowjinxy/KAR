using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionExecutor
    {
        private readonly KarProject _project;

        internal KarProjectResourceActionExecutor(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarProjectResourceActionExecutionResult Execute(
            string address,
            string actionId,
            KarProjectResourceActionExecutionOptions options = null)
        {
            options = options ?? new KarProjectResourceActionExecutionOptions();
            KarProjectResourceActionPlan plan = _project.ResourceService.GetActionPlan(address, actionId, options);
            if (!plan.CanRun)
                throw new InvalidOperationException("KAR resource action cannot run: " + plan.Address + " " + plan.ActionId + ". " + plan.Reason);

            object result;
            switch (plan.ActionId)
            {
                case "output-status":
                    result = _project.ResourceService.GetOutput(address);
                    break;

                case "byte-status":
                    result = _project.ResourceService.GetByteInfo(address);
                    break;

                case "dump-bytes":
                    result = _project.ResourceService.DumpBytesToOutput(address, options.Overwrite);
                    break;

                case "export-output":
                    result = _project.ResourceAddressService.ExportToOutput(address, options.Overwrite);
                    break;

                case "import-file":
                    result = _project.ResourceAddressService.ImportFromFile(address, options.InputPath);
                    break;

                case "field-values":
                    result = options.HasFieldName
                        ? (object)_project.ResourceAddressService.GetFieldValue(address, options.FieldName)
                        : _project.ResourceAddressService.QueryFieldValues(address);
                    break;

                case "set-scalar":
                    result = _project.ResourceAddressService.SetScalarFieldFromText(address, options.FieldName, options.Value);
                    break;

                case "apply-output":
                    result = _project.ResourceService.ApplyOutput(address);
                    break;

                default:
                    throw new ArgumentException("Unsupported KAR resource action: " + plan.ActionId, nameof(actionId));
            }

            return new KarProjectResourceActionExecutionResult(plan, result);
        }
    }
}
