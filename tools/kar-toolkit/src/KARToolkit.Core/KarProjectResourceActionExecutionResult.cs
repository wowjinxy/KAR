using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionExecutionResult
    {
        internal KarProjectResourceActionExecutionResult(
            KarProjectResourceActionPlan plan,
            object result)
        {
            Plan = plan ?? throw new ArgumentNullException(nameof(plan));
            Result = result;
        }

        public KarProjectResourceActionPlan Plan { get; }

        public object Result { get; }

        public KarProjectResourceInfo Resource => Plan.Resource;

        public KarProjectResourceAction Action => Plan.Action;

        public KarResourceReference Reference => Plan.Reference;

        public string Address => Plan.Address;

        public KarResourceKind Kind => Plan.Kind;

        public string ActionId => Plan.ActionId;

        public bool HasResult => Result != null;

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
