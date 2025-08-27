#ifndef INJECT_HOOK_DLL_H
#define INJECT_HOOK_DLL_H
// --------------------------------------------------------------------------------------------- //

#include <stdio.h>
#include <windows.h>
#include <shellapi.h>
#include <strsafe.h>

#include "../builds/debug/detours/detours.h"

VOID
IHDAssertMessage(PCSTR szMsg, PCSTR szFile, DWORD nLine) {
    printf("ASSERT(%s) failed in %s, line %ld.", szMsg, szFile, nLine);
}


#define ASSERT(x)                                                                                  \
    do {                                                                                           \
        if (!(x)) {                                                                                \
            AssertMessage(#x, __FILE__, __LINE__);                                                 \
            DebugBreak();                                                                          \
        }                                                                                          \
    } while (0)
;


// Globals ------------------------------------------------ //
static CHAR s_szDllPath[MAX_PATH] = "";
// -------------------------------------------------------- //



// -------------------------------------------------------------------------- //
//  This code verifies that the named DLL has been configured correctly
//  to be imported into the target process.  DLLs must export a function with
//  ordinal #1 so that the import table touch-up magic works.
//
static BOOL CALLBACK
IHDExportCallback(_In_opt_ PVOID pContext, _In_ ULONG nOrdinal, _In_opt_ LPCSTR pszName,
                  _In_opt_ PVOID pCode) {
    (void)pContext;
    (void)pCode;
    (void)pszName;

    if (nOrdinal == 1) {
        *((BOOL *)pContext) = TRUE;
    }
    return TRUE;
}



static BOOL
IHDDoesDllExportOrdinal1(PCHAR pszDllPath) {
    HMODULE hDll = LoadLibraryExA(pszDllPath, NULL, DONT_RESOLVE_DLL_REFERENCES);
    if (hDll == NULL) {
        printf("InjectHookDll: LoadLibraryEx(%s) failed with error %ld.\n", pszDllPath,
               GetLastError());
        return FALSE;
    }

    BOOL validFlag = FALSE;
    DetourEnumerateExports(hDll, &validFlag, IHDExportCallback);
    FreeLibrary(hDll);
    return validFlag;
}



static BOOL CALLBACK
IHDListBywayCallback(_In_opt_ PVOID pContext, _In_opt_ LPCSTR pszFile,
                     _Outptr_result_maybenull_ LPCSTR *ppszOutFile) {
    (void)pContext;

    *ppszOutFile = pszFile;
    if (pszFile) {
        printf("    %s\n", pszFile);
    }
    return TRUE;
}



static BOOL CALLBACK
IHDListFileCallback(_In_opt_ PVOID pContext, _In_ LPCSTR pszOrigFile, _In_ LPCSTR pszFile,
                    _Outptr_result_maybenull_ LPCSTR *ppszOutFile) {
    (void)pContext;

    *ppszOutFile = pszFile;
    printf("    %s -> %s\n", pszOrigFile, pszFile);
    return TRUE;
}



static BOOL CALLBACK
IHDAddBywayCallback(_In_opt_ PVOID pContext, _In_opt_ LPCSTR pszFile,
                    _Outptr_result_maybenull_ LPCSTR *ppszOutFile) {
    PBOOL pbAddedDll = (PBOOL)pContext;
    if (!pszFile && !*pbAddedDll) { // Add new byway.
        *pbAddedDll = TRUE;
        *ppszOutFile = s_szDllPath;
    }
    return TRUE;
}



BOOL
IHDSetFile(PCHAR pszPath, bool Remove) {
    BOOL bGood = TRUE;
    HANDLE hOld = INVALID_HANDLE_VALUE;
    HANDLE hNew = INVALID_HANDLE_VALUE;
    PDETOUR_BINARY pBinary = NULL;

    CHAR szOrg[MAX_PATH];
    CHAR szNew[MAX_PATH];
    CHAR szOld[MAX_PATH];

    szOld[0] = '\0';
    szNew[0] = '\0';

    StringCchCopyA(szOrg, sizeof(szOrg), pszPath);
    StringCchCopyA(szNew, sizeof(szNew), szOrg);
    StringCchCatA(szNew, sizeof(szNew), "#");
    StringCchCopyA(szOld, sizeof(szOld), szOrg);
    StringCchCatA(szOld, sizeof(szOld), "~");
    printf("  %s:\n", pszPath);

    hOld = CreateFileA(szOrg, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
                       FILE_ATTRIBUTE_NORMAL, NULL);

    if (hOld == INVALID_HANDLE_VALUE) {
        printf("Couldn't open input file: %s, error: %ld\n", szOrg, GetLastError());
        bGood = FALSE;
        goto end;
    }

    hNew = CreateFileA(szNew, GENERIC_WRITE | GENERIC_READ, 0, NULL, CREATE_ALWAYS,
                       FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if (hNew == INVALID_HANDLE_VALUE) {
        printf("Couldn't open output file: %s, error: %ld\n", szNew, GetLastError());
        bGood = FALSE;
        goto end;
    }

    if ((pBinary = DetourBinaryOpen(hOld)) == NULL) {
        printf("DetourBinaryOpen failed: %ld\n", GetLastError());
        goto end;
    }

    if (hOld != INVALID_HANDLE_VALUE) {
        CloseHandle(hOld);
        hOld = INVALID_HANDLE_VALUE;
    }

    {
        BOOL bAddedDll = FALSE;

        DetourBinaryResetImports(pBinary);

        if (!Remove) {
            if (!DetourBinaryEditImports(pBinary, &bAddedDll, IHDAddBywayCallback, NULL, NULL,
                                         NULL)) {
                printf("DetourBinaryEditImports failed: %ld\n", GetLastError());
            }
        }

        if (!DetourBinaryEditImports(pBinary, NULL, IHDListBywayCallback, IHDListFileCallback, NULL,
                                     NULL)) {

            printf("DetourBinaryEditImports failed: %ld\n", GetLastError());
        }

        if (!DetourBinaryWrite(pBinary, hNew)) {
            printf("DetourBinaryWrite failed: %ld\n", GetLastError());
            bGood = FALSE;
        }

        DetourBinaryClose(pBinary);
        pBinary = NULL;

        if (hNew != INVALID_HANDLE_VALUE) {
            CloseHandle(hNew);
            hNew = INVALID_HANDLE_VALUE;
        }

        if (bGood) {
            if (!DeleteFileA(szOld)) {
                DWORD dwError = GetLastError();
                if (dwError != ERROR_FILE_NOT_FOUND) {
                    printf("Warning: Couldn't delete %s: %ld\n", szOld, dwError);
                    bGood = FALSE;
                }
            }
            if (!MoveFileA(szOrg, szOld)) {
                printf("Error: Couldn't back up %s to %s: %ld\n", szOrg, szOld, GetLastError());
                bGood = FALSE;
            }
            if (!MoveFileA(szNew, szOrg)) {
                printf("Error: Couldn't install %s as %s: %ld\n", szNew, szOrg, GetLastError());
                bGood = FALSE;
            }
        }

        DeleteFileA(szNew);
    }


end:
    if (pBinary) {
        DetourBinaryClose(pBinary);
        pBinary = NULL;
    }
    if (hNew != INVALID_HANDLE_VALUE) {
        CloseHandle(hNew);
        hNew = INVALID_HANDLE_VALUE;
    }
    if (hOld != INVALID_HANDLE_VALUE) {
        CloseHandle(hOld);
        hOld = INVALID_HANDLE_VALUE;
    }
    return bGood;
}



int
InjectHookDll(char *Dll, char *Executable, bool Remove) {
    StringCchPrintfA(s_szDllPath, sizeof(s_szDllPath), "%s", Dll);


    if (Remove) {
        printf("Removing extra DLLs from binary files.\n");
    } else {
        if (!IHDDoesDllExportOrdinal1(s_szDllPath)) {
            printf("Error: %hs does not export function with ordinal #1.\n", s_szDllPath);
            return 2;
        }
        printf("Adding %hs to binary files.\n", s_szDllPath);
    }

    if (IHDSetFile(Executable, Remove)) {
        return 0;
    } else {
        return 1;
    }
}

// --------------------------------------------------------------------------------------------- //
#endif
