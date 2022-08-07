#if defined(_WIN32) && defined(_TFS_BUILD_DLL)
 /* We are building TFS as a Win32 DLL */
 #define TEAFSAPI __declspec(dllexport)
#elif defined(_WIN32) && defined(TFS_DLL)
 /* We are calling a TFS Win32 DLL */
 #define TEAFSAPI __declspec(dllimport)
#elif defined(__GNUC__) && defined(_TFS_BUILD_DLL)
 /* We are building TFS as a Unix shared library */
 #define TEAFSAPI __attribute__((visibility("default")))
#else
 #define TEAFSAPI
#endif


TEAFSAPI int TFSFreeBuf();
TEAFSAPI char *TFSReadData(char readPath[]);
TEAFSAPI int TFSWriteData(char writePath[], char writeData[], int writeMode);
TEAFSAPI int RemoveFile(char filePath[]);
TEAFSAPI int TFSCreateFile(char filePath[]);
TEAFSAPI int TFSMoveFile(char oldPath[], char newPath[]);
