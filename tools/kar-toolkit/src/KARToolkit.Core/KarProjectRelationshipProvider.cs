using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectRelationshipProvider
    {
        private readonly Func<KarProject, IEnumerable<KarProjectRelationship>> _createRelationships;

        public KarProjectRelationshipProvider(
            string id,
            string displayName,
            string description,
            Func<KarProject, IEnumerable<KarProjectRelationship>> createRelationships)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Relationship provider id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Relationship provider display name cannot be empty.", nameof(displayName));

            Id = id;
            DisplayName = displayName;
            Description = description ?? "";
            _createRelationships = createRelationships ?? throw new ArgumentNullException(nameof(createRelationships));
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public IReadOnlyList<KarProjectRelationship> CreateRelationships(KarProject project)
        {
            if (project == null)
                throw new ArgumentNullException(nameof(project));

            return _createRelationships(project)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectRelationshipProviderContract CreateContract()
        {
            return KarProjectRelationshipProviderContract.Create(this);
        }
    }
}
