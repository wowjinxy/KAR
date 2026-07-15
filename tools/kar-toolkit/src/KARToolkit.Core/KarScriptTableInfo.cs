namespace KARToolkit.Core
{
    public sealed class KarScriptTableInfo
    {
        internal KarScriptTableInfo(
            string name,
            string role,
            string category,
            string description)
        {
            Name = name;
            Role = role;
            Category = category;
            Description = description;
        }

        public string Name { get; }

        public string Role { get; }

        public string Category { get; }

        public string Description { get; }
    }
}
