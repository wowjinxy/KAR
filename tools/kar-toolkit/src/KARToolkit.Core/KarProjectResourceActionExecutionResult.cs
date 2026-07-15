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
