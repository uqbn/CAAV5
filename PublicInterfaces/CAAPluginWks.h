#ifdef _WINDOWS_SOURCE
#ifdef __CAAPluginWks
#define ExportedByCAAPluginWks __declspec(dllexport)
#else
#define ExportedByCAAPluginWks __declspec(dllimport)
#endif
#else
#define ExportedByCAAPluginWks
#endif
