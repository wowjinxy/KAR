using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceHandlerRegistry
    {
        public static KarProjectResourceHandlerRegistry Default { get; } =
            new KarProjectResourceHandlerRegistry(CreateDefaultHandlers());

        private readonly IReadOnlyList<KarProjectResourceHandler> _handlers;
        private readonly Dictionary<KarResourceKind, KarProjectResourceHandler> _handlersByKind;
        private readonly Dictionary<string, KarProjectResourceHandler> _handlersById;

        public KarProjectResourceHandlerRegistry(IEnumerable<KarProjectResourceHandler> handlers)
        {
            if (handlers == null)
                throw new ArgumentNullException(nameof(handlers));

            _handlers = handlers
                .ToList()
                .AsReadOnly();
            _handlersByKind = new Dictionary<KarResourceKind, KarProjectResourceHandler>();
            _handlersById = new Dictionary<string, KarProjectResourceHandler>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectResourceHandler handler in _handlers)
            {
                if (handler == null)
                    throw new ArgumentException("Resource handlers cannot contain null entries.", nameof(handlers));
                if (_handlersByKind.ContainsKey(handler.Kind))
                    throw new ArgumentException("Duplicate resource handler kind: " + handler.Kind, nameof(handlers));
                if (_handlersById.ContainsKey(handler.Id))
                    throw new ArgumentException("Duplicate resource handler id: " + handler.Id, nameof(handlers));

                _handlersByKind.Add(handler.Kind, handler);
                _handlersById.Add(handler.Id, handler);
            }

            foreach (KarResourceKind kind in Enum.GetValues(typeof(KarResourceKind)))
            {
                if (!_handlersByKind.ContainsKey(kind))
                    throw new ArgumentException("Missing resource handler for kind: " + kind, nameof(handlers));
            }
        }

        public IReadOnlyList<KarProjectResourceHandler> Handlers => _handlers;

        public KarProjectResourceHandler GetHandler(KarResourceKind kind)
        {
            KarProjectResourceHandler handler;
            if (!TryGetHandler(kind, out handler))
                throw new KeyNotFoundException("KAR resource handler was not found: " + kind);

            return handler;
        }

        public bool TryGetHandler(KarResourceKind kind, out KarProjectResourceHandler handler)
        {
            return _handlersByKind.TryGetValue(kind, out handler);
        }

        public KarProjectResourceHandler FindHandler(string idOrKind)
        {
            KarProjectResourceHandler handler;
            if (!TryFindHandler(idOrKind, out handler))
                throw new KeyNotFoundException("KAR resource handler was not found: " + idOrKind);

            return handler;
        }

        public bool TryFindHandler(string idOrKind, out KarProjectResourceHandler handler)
        {
            handler = null;
            if (string.IsNullOrWhiteSpace(idOrKind))
                return false;

            if (_handlersById.TryGetValue(idOrKind, out handler))
                return true;

            KarResourceKind kind;
            return Enum.TryParse(idOrKind, true, out kind) && TryGetHandler(kind, out handler);
        }

        private static IReadOnlyList<KarProjectResourceHandler> CreateDefaultHandlers()
        {
            return new[]
            {
                Define(
                    KarResourceKind.File,
                    "file",
                    "Project File",
                    "Whole project file resource.",
                    KarProjectResourceCapability.QueryOutput |
                    KarProjectResourceCapability.ReadBytes |
                    KarProjectResourceCapability.ExportToOutput |
                    KarProjectResourceCapability.ImportFromFile),

                Define(
                    KarResourceKind.HsdRoot,
                    "hsd-root",
                    "HSD Root",
                    "Named root inside an HSD archive.",
                    KarProjectResourceCapability.QueryOutput |
                    KarProjectResourceCapability.ExportToOutput |
                    KarProjectResourceCapability.QueryFieldValues |
                    KarProjectResourceCapability.SetScalarFields),

                Define(
                    KarResourceKind.A2DEntry,
                    "a2d-entry",
                    "A2D Entry",
                    "Embedded entry inside an A2D package.",
                    KarProjectResourceCapability.QueryOutput |
                    KarProjectResourceCapability.ReadBytes |
                    KarProjectResourceCapability.ExportToOutput |
                    KarProjectResourceCapability.ImportFromFile |
                    KarProjectResourceCapability.ApplyOutput),
            };
        }

        private static KarProjectResourceHandler Define(
            KarResourceKind kind,
            string id,
            string displayName,
            string description,
            KarProjectResourceCapability capabilities)
        {
            return new KarProjectResourceHandler(kind, id, displayName, description, capabilities);
        }
    }
}
