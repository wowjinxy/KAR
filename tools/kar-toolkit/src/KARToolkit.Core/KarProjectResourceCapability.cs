using System;

namespace KARToolkit.Core
{
    [Flags]
    public enum KarProjectResourceCapability
    {
        None = 0,
        QueryOutput = 1 << 0,
        ReadBytes = 1 << 1,
        ExportToOutput = 1 << 2,
        ImportFromFile = 1 << 3,
        QueryFieldValues = 1 << 4,
        SetScalarFields = 1 << 5,
        ApplyOutput = 1 << 6,
    }
}
