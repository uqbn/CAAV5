#ifdef _WINDOWS_SOURCE
#ifdef __CAAPluginCmd
#define ExportedByCAAPluginCmd __declspec(dllexport)
#else
#define ExportedByCAAPluginCmd __declspec(dllimport)
#endif
#else
#define ExportedByCAAPluginCmd
#endif
