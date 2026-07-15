using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionExecutionResult
    {
        internal KarProjectResourceActionExecutionResult(
            KarProjectResourceActionPlan plan,
            object result)
            : this(plan, result, null)
        {
        }

        internal KarProjectResourceActionExecutionResult(
            KarProjectResourceActionPlan plan,
            object result,
            Exception error)
        {
            Plan = plan ?? throw new ArgumentNullException(nameof(plan));
            Result = result;
            Error = error;
        }

        public KarProjectResourceActionPlan Plan { get; }

        public object Result { get; }

        public Exception Error { get; }

        public KarProjectResourceInfo Resource => Plan.Resource;

        public KarProjectResourceAction Action => Plan.Action;

        public KarResourceReference Reference => Plan.Reference;

        public string Address => Plan.Address;

        public KarResourceKind Kind => Plan.Kind;

        public string ActionId => Plan.ActionId;

        public bool Succeeded => Error == null;

        public bool Failed => Error != null;

        public bool HasResult => Result != null;

        public string ErrorType => Error == null ? null : Error.GetType().Name;

        public string ErrorMessage => Error == null ? null : Error.Message;

        public bool IsReadOnly => Plan.IsReadOnly;

        public bool WritesOutput => Plan.WritesOutput;

        public bool WouldWriteOutput => Plan.WouldWriteOutput;

        public bool WroteOutput
        {
            get
            {
                if (Failed)
                    return false;
                if (ByteDumpResult != null)
                    return ByteDumpResult.WroteOutput;
                if (ExportResult != null)
                    return ExportResult.WroteOutput;
                if (ImportResult != null || ScalarEditResult != null || OutputApplyResult != null)
                    return true;

                return false;
            }
        }

        public bool SkippedOutputWrite => Succeeded && WritesOutput && !WroteOutput;

        public string ResultKind
        {
            get
            {
                if (Failed)
                    return "error";
                if (OutputInfo != null)
                    return "output-status";
                if (ByteInfo != null)
                    return "byte-status";
                if (ByteDumpResult != null)
                    return "byte-dump";
                if (ExportResult != null)
                    return "export";
                if (ImportResult != null)
                    return "import";
                if (FieldValue != null)
                    return "field-value";
                if (FieldValues != null)
                    return "field-values";
                if (ScalarEditResult != null)
                    return "scalar-edit";
                if (OutputApplyResult != null)
                    return "output-apply";

                return "none";
            }
        }

        public string OutputRelativePath
        {
            get
            {
                if (ByteDumpResult != null)
                    return ByteDumpResult.OutputRelativePath;
                if (ExportResult != null)
                    return ExportResult.OutputRelativePath;
                if (ImportResult != null)
                    return ImportResult.OutputRelativePath;
                if (OutputInfo != null)
                    return OutputInfo.OutputRelativePath;
                if (Plan.OutputRelativePath != null)
                    return Plan.OutputRelativePath;

                return null;
            }
        }

        public string OutputPath
        {
            get
            {
                if (ByteDumpResult != null)
                    return ByteDumpResult.OutputPath;
                if (ExportResult != null)
                    return ExportResult.OutputPath;
                if (ImportResult != null)
                    return ImportResult.OutputPath;
                if (ScalarEditResult != null)
                    return ScalarEditResult.OutputPath;
                if (OutputApplyResult != null)
                    return OutputApplyResult.PackageOutputPath;
                if (OutputInfo != null)
                    return OutputInfo.OutputPath;
                if (Plan.OutputPath != null)
                    return Plan.OutputPath;

                return null;
            }
        }

        public KarProjectResourceOutputInfo OutputInfo => Result as KarProjectResourceOutputInfo;

        public KarProjectResourceByteInfo ByteInfo => Result as KarProjectResourceByteInfo;

        public KarProjectResourceByteDumpResult ByteDumpResult => Result as KarProjectResourceByteDumpResult;

        public KarProjectResourceExportResult ExportResult => Result as KarProjectResourceExportResult;

        public KarProjectResourceImportResult ImportResult => Result as KarProjectResourceImportResult;

        public KarProjectResourceFieldInfo FieldValue => Result as KarProjectResourceFieldInfo;

        public IReadOnlyList<KarProjectResourceFieldInfo> FieldValues => Result as IReadOnlyList<KarProjectResourceFieldInfo>;

        public KarProjectResourceScalarEditResult ScalarEditResult => Result as KarProjectResourceScalarEditResult;

        public KarProjectResourceOutputApplyResult OutputApplyResult => Result as KarProjectResourceOutputApplyResult;
    }
}
