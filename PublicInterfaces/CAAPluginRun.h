#ifdef _WINDOWS_SOURCE
#ifdef __CAAPluginRun
#define ExportedByCAAPluginRun __declspec(dllexport)
#else
#define ExportedByCAAPluginRun __declspec(dllimport)
#endif
#else
#define ExportedByCAAPluginRun
#endif
