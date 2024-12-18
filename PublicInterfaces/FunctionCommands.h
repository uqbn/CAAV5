#ifdef _WINDOWS_SOURCE
#ifdef __FunctionCommands
#define ExportedByFunctionCommands __declspec(dllexport)
#else
#define ExportedByFunctionCommands __declspec(dllimport)
#endif
#else
#define ExportedByFunctionCommands
#endif
