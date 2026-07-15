using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionPlan
    {
        internal KarProjectResourceActionPlan(
            KarProjectResourceInfo resource,
            KarProjectResourceAction action,
            KarProjectResourceOutputInfo output,
            KarProjectResourceByteInfo byteInfo,
            bool overwrite,
            bool canRun,
            bool wouldWriteOutput,
            string reason)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            Action = action ?? throw new ArgumentNullException(nameof(action));
            Output = output;
            ByteInfo = byteInfo;
            Overwrite = overwrite;
            CanRun = canRun;
            WouldWriteOutput = wouldWriteOutput;
            Reason = reason ?? "";
        }

        public KarProjectResourceInfo Resource { get; }

        public KarProjectResourceAction Action { get; }

        public KarProjectResourceOutputInfo Output { get; }

        public KarProjectResourceByteInfo ByteInfo { get; }

        public KarResourceReference Reference => Resource.Reference;

        public string Address => Resource.Address;

        public KarResourceKind Kind => Resource.Kind;

        public string ActionId => Action.Id;

        public string Command => Action.Command;

        public bool Overwrite { get; }

        public bool CanRun { get; }

        public bool WouldWriteOutput { get; }

        public bool IsReadOnly => Action.IsReadOnly;

        public bool WritesOutput => Action.WritesOutput;

        public bool RequiresInputFile => Action.RequiresInputFile;

        public bool RequiresFieldName => Action.RequiresFieldName;

        public bool RequiresValue => Action.RequiresValue;

        public bool SupportsBatch => Action.SupportsBatch;

        public bool HasOutputInfo => Output != null;

        public bool HasByteInfo => ByteInfo != null;

        public KarProjectResourceOutputKind? OutputKind => Output == null ? (KarProjectResourceOutputKind?)null : Output.OutputKind;

        public KarProjectResourceOutputStatus? OutputStatus => Output == null ? (KarProjectResourceOutputStatus?)null : Output.Status;

        public KarProjectResourceByteOutputStatus? ByteStatus => ByteInfo == null ? (KarProjectResourceByteOutputStatus?)null : ByteInfo.Status;

        public string OutputRelativePath => Output != null ? Output.OutputRelativePath : ByteInfo == null ? null : ByteInfo.OutputRelativePath;

        public string OutputPath => Output != null ? Output.OutputPath : ByteInfo == null ? null : ByteInfo.OutputPath;

        public string Reason { get; }

        public KarProjectResourceActionPlanContract CreateContract()
        {
            return KarProjectResourceActionPlanContract.Create(this);
        }
    }
}
