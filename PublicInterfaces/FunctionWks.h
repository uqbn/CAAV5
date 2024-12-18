#ifdef _WINDOWS_SOURCE
#ifdef __FunctionWks
#define ExportedByFunctionWks __declspec(dllexport)
#else
#define ExportedByFunctionWks __declspec(dllimport)
#endif
#else
#define ExportedByFunctionWks
#endif
