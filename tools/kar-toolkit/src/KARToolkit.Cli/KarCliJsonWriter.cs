using System.Text.Json;
using System.Text.Json.Serialization;

namespace KARToolkit.Cli;

internal static class KarCliJsonWriter
{
    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        WriteIndented = true,
        DefaultIgnoreCondition = JsonIgnoreCondition.WhenWritingNull,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
    };

    public static void WriteJson(object value)
    {
        Console.WriteLine(JsonSerializer.Serialize(value, JsonOptions));
    }
}
