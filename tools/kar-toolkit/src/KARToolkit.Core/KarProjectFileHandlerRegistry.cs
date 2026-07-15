using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileHandlerRegistry
    {
        public static KarProjectFileHandlerRegistry Default { get; } =
            new KarProjectFileHandlerRegistry(KarFileKindRegistry.Default);

        private readonly IReadOnlyList<KarProjectFileHandler> _handlers;
        private readonly Dictionary<KarFileKind, KarProjectFileHandler> _handlersByKind;
        private readonly Dictionary<string, KarProjectFileHandler> _handlersById;

        public KarProjectFileHandlerRegistry(KarFileKindRegistry fileKinds)
            : this(
                fileKinds ?? throw new ArgumentNullException(nameof(fileKinds)),
                fileKinds.Descriptors.Select(KarProjectFileHandler.CreateDefault))
        {
        }

        public KarProjectFileHandlerRegistry(
            KarFileKindRegistry fileKinds,
            IEnumerable<KarProjectFileHandler> handlers)
        {
            FileKindRegistry = fileKinds ?? throw new ArgumentNullException(nameof(fileKinds));
            if (handlers == null)
                throw new ArgumentNullException(nameof(handlers));

            _handlers = handlers
                .ToList()
                .AsReadOnly();
            _handlersByKind = new Dictionary<KarFileKind, KarProjectFileHandler>();
            _handlersById = new Dictionary<string, KarProjectFileHandler>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectFileHandler handler in _handlers)
            {
                if (handler == null)
                    throw new ArgumentException("File handlers cannot contain null entries.", nameof(handlers));
                if (!FileKindRegistry.TryGetDescriptor(handler.Kind, out KarFileKindDescriptor descriptor) ||
                    !object.ReferenceEquals(descriptor, handler.Descriptor))
                {
                    throw new ArgumentException("File handler descriptor is not owned by the file kind registry: " + handler.Kind, nameof(handlers));
                }
                if (_handlersByKind.ContainsKey(handler.Kind))
                    throw new ArgumentException("Duplicate file handler kind: " + handler.Kind, nameof(handlers));
                if (_handlersById.ContainsKey(handler.Id))
                    throw new ArgumentException("Duplicate file handler id: " + handler.Id, nameof(handlers));

                _handlersByKind.Add(handler.Kind, handler);
                _handlersById.Add(handler.Id, handler);
            }

            foreach (KarFileKindDescriptor descriptor in FileKindRegistry.Descriptors)
            {
                if (!_handlersByKind.ContainsKey(descriptor.Kind))
                    throw new ArgumentException("Missing file handler for kind: " + descriptor.Kind, nameof(handlers));
            }
        }

        public KarFileKindRegistry FileKindRegistry { get; }

        public IReadOnlyList<KarProjectFileHandler> Handlers => _handlers;

        public KarProjectFileHandler GetHandler(KarFileKind kind)
        {
            KarProjectFileHandler handler;
            if (!TryGetHandler(kind, out handler))
                throw new KeyNotFoundException("KAR file handler was not found: " + kind);

            return handler;
        }

        public bool TryGetHandler(KarFileKind kind, out KarProjectFileHandler handler)
        {
            return _handlersByKind.TryGetValue(kind, out handler);
        }

        public KarProjectFileHandler FindHandler(string idOrKind)
        {
            KarProjectFileHandler handler;
            if (!TryFindHandler(idOrKind, out handler))
                throw new KeyNotFoundException("KAR file handler was not found: " + idOrKind);

            return handler;
        }

        public bool TryFindHandler(string idOrKind, out KarProjectFileHandler handler)
        {
            handler = null;
            if (string.IsNullOrWhiteSpace(idOrKind))
                return false;

            if (_handlersById.TryGetValue(idOrKind, out handler))
                return true;

            KarFileKind kind;
            return Enum.TryParse(idOrKind, true, out kind) && TryGetHandler(kind, out handler);
        }

        public KarProjectFileHandler GetHandler(KarFileKindMatch match)
        {
            if (match == null)
                throw new ArgumentNullException(nameof(match));

            return GetHandler(match.Kind);
        }
    }
}
