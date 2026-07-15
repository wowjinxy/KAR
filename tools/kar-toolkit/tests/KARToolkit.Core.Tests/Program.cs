using System;
using System.Collections.Generic;
using System.Linq;
using KARToolkit.Core;

namespace KARToolkit.Core.Tests
{
    internal static class Program
    {
        private static readonly List<string> Failures = new List<string>();
        private static int _assertionCount;

        public static int Main()
        {
            Run("BuiltInCatalogHasExpectedCoreSchemas", BuiltInCatalogHasExpectedCoreSchemas);
            Run("BuiltInFieldReferencesResolve", BuiltInFieldReferencesResolve);
            Run("FixedSizeDefinitionsContainTheirFields", FixedSizeDefinitionsContainTheirFields);
            Run("RegistryRejectsAmbiguousDefinitions", RegistryRejectsAmbiguousDefinitions);
            Run("DefinitionRejectsAmbiguousFields", DefinitionRejectsAmbiguousFields);

            if (Failures.Count > 0)
            {
                Console.Error.WriteLine("KARToolkit.Core.Tests failed:");
                foreach (string failure in Failures)
                    Console.Error.WriteLine("  " + failure);
                return 1;
            }

            Console.WriteLine("KARToolkit.Core.Tests passed: " + _assertionCount + " assertions.");
            return 0;
        }

        private static void BuiltInCatalogHasExpectedCoreSchemas()
        {
            KarDataDefinitionRegistry registry = KarDataDefinitionCatalog.BuiltIn;
            AssertTrue(KarDataDefinitionCatalog.All.Count >= 32, "built-in catalog should contain the current schema set");
            AssertResolves(registry, "kar.gr.data", "KAR_grData");
            AssertResolves(registry, "kar.gr.itemNode", "KAR_grItemNode");
            AssertResolves(registry, "kar.gr.itemCityTrial", "KAR_grItemNodeCityTrial");
            AssertResolves(registry, "kar.vs.legendary", "KAR_vsLegendaryData");
            AssertResolves(registry, "kar.vc.common", "KAR_vcDataCommon");
        }

        private static void BuiltInFieldReferencesResolve()
        {
            KarDataDefinitionRegistry registry = KarDataDefinitionCatalog.BuiltIn;

            foreach (KarDataDefinition definition in registry.All)
            {
                foreach (KarDataFieldDefinition field in definition.Fields)
                {
                    if (string.IsNullOrWhiteSpace(field.DataDefinitionId))
                        continue;

                    AssertTrue(
                        field.IsPointer,
                        definition.Id + "." + field.Name + " has a nested schema id but is not marked as a pointer");

                    KarDataDefinition nestedDefinition;
                    AssertTrue(
                        registry.TryGet(field.DataDefinitionId, out nestedDefinition),
                        definition.Id + "." + field.Name + " references missing schema " + field.DataDefinitionId);
                }
            }
        }

        private static void FixedSizeDefinitionsContainTheirFields()
        {
            foreach (KarDataDefinition definition in KarDataDefinitionCatalog.All)
            {
                if (!definition.Size.HasValue)
                    continue;

                foreach (KarDataFieldDefinition field in definition.Fields)
                {
                    if (!field.Offset.HasValue)
                        continue;

                    AssertTrue(field.Offset.Value >= 0, definition.Id + "." + field.Name + " has a negative offset");

                    int fieldSize;
                    if (!TryGetFixedFieldSize(field, out fieldSize))
                        continue;

                    int endOffset = field.Offset.Value + fieldSize;
                    AssertTrue(
                        endOffset <= definition.Size.Value,
                        definition.Id + "." + field.Name + " ends at 0x" + endOffset.ToString("X") +
                            ", past definition size " + definition.SizeHex);
                }
            }
        }

        private static void RegistryRejectsAmbiguousDefinitions()
        {
            KarDataDefinition first = MakeDefinition("kar.test.first", "TestAccessor");
            KarDataDefinition duplicateId = MakeDefinition("kar.test.first", "OtherAccessor");
            KarDataDefinition duplicateAccessor = MakeDefinition("kar.test.second", "TestAccessor");

            AssertThrows<ArgumentException>(
                () => new KarDataDefinitionRegistry(new[] { first, duplicateId }),
                "duplicate definition ids should fail");
            AssertThrows<ArgumentException>(
                () => new KarDataDefinitionRegistry(new[] { first, duplicateAccessor }),
                "duplicate accessor mappings should fail");
        }

        private static void DefinitionRejectsAmbiguousFields()
        {
            AssertThrows<ArgumentException>(
                () => new KarDataDefinition(
                    "kar.test.definition",
                    "Test Definition",
                    "Tests",
                    "TestAccessor",
                    "Test definition.",
                    "tests",
                    new[]
                    {
                        new KarDataFieldDefinition("x00", 0, "s32", "First field."),
                        new KarDataFieldDefinition("X00", 4, "s32", "Duplicate field."),
                    }),
                "duplicate field names should fail");
        }

        private static void AssertResolves(KarDataDefinitionRegistry registry, string id, string accessorTypeName)
        {
            KarDataDefinition byId;
            KarDataDefinition byAccessor;
            KarDataDefinition byFind;

            AssertTrue(registry.TryGet(id, out byId), "registry should resolve " + id + " by id");
            AssertTrue(registry.TryGetByAccessorTypeName(accessorTypeName, out byAccessor), "registry should resolve " + accessorTypeName + " by accessor");
            AssertTrue(registry.TryFind(accessorTypeName, out byFind), "registry should find " + accessorTypeName);
            AssertTrue(object.ReferenceEquals(byId, byAccessor), id + " id/accessor lookup should return the same definition");
            AssertTrue(object.ReferenceEquals(byId, byFind), id + " find lookup should return the same definition");
        }

        private static KarDataDefinition MakeDefinition(string id, string accessorTypeName)
        {
            return new KarDataDefinition(
                id,
                "Test Definition",
                "Tests",
                accessorTypeName,
                "Test definition.",
                "tests",
                new[] { new KarDataFieldDefinition("x00", 0, "s32", "Test field.") },
                4);
        }

        private static bool TryGetFixedFieldSize(KarDataFieldDefinition field, out int size)
        {
            if (field.IsPointer)
            {
                size = 4;
                return true;
            }

            switch ((field.TypeName ?? "").Trim().ToLowerInvariant())
            {
                case "s8":
                case "u8":
                case "byte":
                    size = 1;
                    return true;
                case "s16":
                case "u16":
                    size = 2;
                    return true;
                case "s32":
                case "u32":
                case "int":
                case "int32":
                case "uint":
                case "uint32":
                case "f32":
                case "float":
                case "single":
                    size = 4;
                    return true;
                default:
                    size = 0;
                    return false;
            }
        }

        private static void Run(string name, Action test)
        {
            try
            {
                test();
            }
            catch (Exception ex)
            {
                Failures.Add(name + ": unexpected " + ex.GetType().Name + ": " + ex.Message);
            }
        }

        private static void AssertTrue(bool condition, string message)
        {
            _assertionCount++;
            if (!condition)
                Failures.Add(message);
        }

        private static void AssertThrows<TException>(Action action, string message)
            where TException : Exception
        {
            _assertionCount++;
            try
            {
                action();
                Failures.Add(message + " (no exception thrown)");
            }
            catch (TException)
            {
            }
            catch (Exception ex)
            {
                Failures.Add(message + " (threw " + ex.GetType().Name + ")");
            }
        }
    }
}
