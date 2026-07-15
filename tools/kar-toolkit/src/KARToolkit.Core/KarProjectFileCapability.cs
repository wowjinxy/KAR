using System;

namespace KARToolkit.Core
{
    [Flags]
    public enum KarProjectFileCapability
    {
        None = 0,
        ReadBytes = 1 << 0,
        CopyToOutput = 1 << 1,
        ReplaceFileInOutput = 1 << 2,
        InspectHsdArchive = 1 << 3,
        QueryHsdRoots = 1 << 4,
        EditHsdScalarFields = 1 << 5,
        OpenA2DPackage = 1 << 6,
        ListA2DEntries = 1 << 7,
        ExtractA2DEntries = 1 << 8,
        ReplaceA2DEntries = 1 << 9,
        ListScriptTables = 1 << 10,
        GroupWithMap = 1 << 11,
        InspectMapArchive = 1 << 12,
    }
}
