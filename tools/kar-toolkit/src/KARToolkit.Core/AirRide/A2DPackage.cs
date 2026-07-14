using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace KARToolkit.Core.AirRide
{
    public class A2DPackage
    {
        private readonly List<A2DPackageEntry> _entries;

        public string FilePath { get; }

        public byte[] Data { get; }

        public bool HasFileSizeWord { get; }

        public bool Modified { get; private set; }

        public IReadOnlyList<A2DPackageEntry> Entries => _entries;

        private A2DPackage(string filePath, byte[] data, bool hasFileSizeWord, List<A2DPackageEntry> entries)
        {
            FilePath = filePath;
            Data = data;
            HasFileSizeWord = hasFileSizeWord;
            _entries = entries;
        }

        public static bool IsA2DPackage(string filePath)
        {
            return TryOpen(filePath, out _, out _);
        }

        public static bool TryOpen(string filePath, out A2DPackage package, out string error)
        {
            package = null;
            error = null;

            if (string.IsNullOrEmpty(filePath) || !File.Exists(filePath))
            {
                error = "File does not exist.";
                return false;
            }

            byte[] data = File.ReadAllBytes(filePath);
            return TryParse(filePath, data, out package, out error);
        }

        public static bool TryParse(byte[] data, out A2DPackage package, out string error)
        {
            return TryParse(null, data, out package, out error);
        }

        public byte[] GetEntryData(int index)
        {
            A2DPackageEntry entry = _entries[index];
            byte[] output = new byte[entry.Size];
            Buffer.BlockCopy(Data, entry.DataOffset, output, 0, output.Length);
            return output;
        }

        public bool TryGetEntryHSDArchiveData(int index, out byte[] archiveData, out string error)
        {
            archiveData = null;
            error = null;

            if (index < 0 || index >= _entries.Count)
            {
                error = "No resource is selected.";
                return false;
            }

            A2DPackageEntry entry = _entries[index];
            if (entry.Size < 0x24)
            {
                error = "Resource is too small to contain a wrapped HSD archive.";
                return false;
            }

            int archiveOffset = entry.DataOffset + 4;
            int availableSize = entry.Size - 4;
            if (!TryReadHSDArchiveHeader(archiveOffset, availableSize, out int archiveSize, out error))
                return false;

            uint wrapperSize = ReadUInt32(Data, entry.DataOffset);
            if (wrapperSize != archiveSize)
            {
                error = "Resource wrapper size does not match the inner HSD archive size.";
                return false;
            }

            archiveData = new byte[archiveSize];
            Buffer.BlockCopy(Data, archiveOffset, archiveData, 0, archiveData.Length);
            return true;
        }

        public bool ReplaceEntry(int index, string replacementPath, out string error)
        {
            error = null;

            if (string.IsNullOrEmpty(replacementPath) || !File.Exists(replacementPath))
            {
                error = "Replacement file does not exist.";
                return false;
            }

            return ReplaceEntry(index, File.ReadAllBytes(replacementPath), out error);
        }

        public bool ReplaceEntry(int index, byte[] replacement, out string error)
        {
            error = null;

            if (index < 0 || index >= _entries.Count)
            {
                error = "No resource is selected.";
                return false;
            }

            if (replacement == null)
            {
                error = "Replacement data is empty.";
                return false;
            }

            A2DPackageEntry entry = _entries[index];
            if (replacement.Length != entry.Size)
            {
                error = $"Replacement must be exactly 0x{entry.Size:X} bytes. The selected data is 0x{replacement.Length:X} bytes.";
                return false;
            }

            Buffer.BlockCopy(replacement, 0, Data, entry.DataOffset, entry.Size);
            Modified = true;
            return true;
        }

        public void Save(string filePath)
        {
            string directory = Path.GetDirectoryName(filePath);
            if (!string.IsNullOrEmpty(directory))
                Directory.CreateDirectory(directory);

            File.WriteAllBytes(filePath, Data);
            Modified = false;
        }

        private static bool TryParse(string filePath, byte[] data, out A2DPackage package, out string error)
        {
            package = null;
            error = null;

            if (data == null || data.Length < 0x10)
            {
                error = "File is too small to be an A2D package.";
                return false;
            }

            uint firstWord = ReadUInt32(data, 0);
            uint count = ReadUInt32(data, 4);
            bool hasFileSizeWord = firstWord == data.Length;

            if (firstWord != 0 && !hasFileSizeWord)
            {
                error = "File does not use the A2D package header.";
                return false;
            }

            if (count == 0 || count > 4096)
            {
                error = "A2D package resource count is invalid.";
                return false;
            }

            long pairTableEnd = 8L + count * 8L;
            if (pairTableEnd > data.Length)
            {
                error = "A2D package table extends past the end of the file.";
                return false;
            }

            List<RawEntry> rawEntries = new List<RawEntry>();
            for (int i = 0; i < count; i++)
            {
                int pairOffset = 8 + i * 8;
                if (!TryReadOffset(ReadUInt32(data, pairOffset), data.Length, out int nameOffset) ||
                    !TryReadOffset(ReadUInt32(data, pairOffset + 4), data.Length, out int dataOffset))
                {
                    error = "A2D package offset points outside the file.";
                    return false;
                }

                if (nameOffset < pairTableEnd || dataOffset < pairTableEnd)
                {
                    error = "A2D package contains an offset inside the resource table.";
                    return false;
                }

                rawEntries.Add(new RawEntry(nameOffset, dataOffset));
            }

            if (!rawEntries.Select(e => e.NameOffset).SequenceEqual(rawEntries.Select(e => e.NameOffset).OrderBy(e => e)) ||
                !rawEntries.Select(e => e.DataOffset).SequenceEqual(rawEntries.Select(e => e.DataOffset).OrderBy(e => e)))
            {
                error = "A2D package name or data offsets are not ordered.";
                return false;
            }

            int firstDataOffset = rawEntries[0].DataOffset;
            List<A2DPackageEntry> entries = new List<A2DPackageEntry>();
            for (int i = 0; i < rawEntries.Count; i++)
            {
                RawEntry raw = rawEntries[i];
                string name = ReadNullTerminatedAscii(data, raw.NameOffset, firstDataOffset);
                if (string.IsNullOrEmpty(name))
                {
                    error = "A2D package contains an empty resource name.";
                    return false;
                }

                int nextDataOffset = i + 1 < rawEntries.Count ? rawEntries[i + 1].DataOffset : data.Length;
                if (nextDataOffset < raw.DataOffset)
                {
                    error = "A2D package resource sizes are invalid.";
                    return false;
                }

                entries.Add(new A2DPackageEntry(i, name, raw.NameOffset, raw.DataOffset, nextDataOffset - raw.DataOffset));
            }

            package = new A2DPackage(filePath, data, hasFileSizeWord, entries);
            return true;
        }

        private static uint ReadUInt32(byte[] data, int offset)
        {
            return ((uint)data[offset] << 24) |
                ((uint)data[offset + 1] << 16) |
                ((uint)data[offset + 2] << 8) |
                data[offset + 3];
        }

        private static bool TryReadOffset(uint offset, int fileSize, out int checkedOffset)
        {
            checkedOffset = 0;
            if (offset >= fileSize)
                return false;

            checkedOffset = (int)offset;
            return true;
        }

        private bool TryReadHSDArchiveHeader(int offset, int availableSize, out int archiveSize, out string error)
        {
            archiveSize = 0;
            error = null;

            if (offset < 0 || availableSize < 0x20 || offset + availableSize > Data.Length)
            {
                error = "Resource is too small to contain an HSD archive header.";
                return false;
            }

            uint rawArchiveSize = ReadUInt32(Data, offset);
            uint rawDataSize = ReadUInt32(Data, offset + 4);
            uint rawRelocCount = ReadUInt32(Data, offset + 8);
            uint rawRootCount = ReadUInt32(Data, offset + 12);
            uint rawRefCount = ReadUInt32(Data, offset + 16);

            if (rawArchiveSize < 0x20 || rawArchiveSize > availableSize || rawArchiveSize > int.MaxValue)
            {
                error = "Inner HSD archive size is invalid.";
                return false;
            }

            archiveSize = (int)rawArchiveSize;
            if (rawDataSize + 0x20UL > (ulong)archiveSize)
            {
                error = "Inner HSD archive data section extends past the archive size.";
                return false;
            }

            ulong relocOffset = rawDataSize + 0x20UL;
            ulong rootTableOffset = relocOffset + rawRelocCount * 4UL;
            ulong stringStart = rootTableOffset + (rawRootCount + rawRefCount) * 8UL;
            if (rootTableOffset > (ulong)archiveSize || stringStart > (ulong)archiveSize)
            {
                error = "Inner HSD archive relocation/root tables extend past the archive size.";
                return false;
            }

            return true;
        }

        private static string ReadNullTerminatedAscii(byte[] data, int offset, int limit)
        {
            if (offset < 0 || offset >= limit || limit > data.Length)
                return null;

            int end = offset;
            while (end < limit && data[end] != 0)
            {
                if (data[end] < 0x20 || data[end] > 0x7E)
                    return null;

                end++;
            }

            if (end == limit)
                return null;

            return Encoding.ASCII.GetString(data, offset, end - offset);
        }

        private readonly struct RawEntry
        {
            public int NameOffset { get; }

            public int DataOffset { get; }

            public RawEntry(int nameOffset, int dataOffset)
            {
                NameOffset = nameOffset;
                DataOffset = dataOffset;
            }
        }
    }

    public class A2DPackageEntry
    {
        public int Index { get; }

        public string Name { get; }

        public int NameOffset { get; }

        public int DataOffset { get; }

        public int Size { get; }

        public string Kind => Path.GetExtension(Name).TrimStart('.');

        public A2DPackageEntry(int index, string name, int nameOffset, int dataOffset, int size)
        {
            Index = index;
            Name = name;
            NameOffset = nameOffset;
            DataOffset = dataOffset;
            Size = size;
        }
    }
}
