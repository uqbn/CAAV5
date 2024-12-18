#ifdef _WINDOWS_SOURCE
#ifdef __Function
#define ExportedByFunction __declspec(dllexport)
#else
#define ExportedByFunction __declspec(dllimport)
#endif
#else
#define ExportedByFunction
#endif
