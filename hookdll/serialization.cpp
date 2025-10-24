#ifndef SERIALIZATION_H
#define SERIALIZATION_H
// ---------------------------------------------------------------------------------------------- //

#include <cstdint>
#include <BaseTsd.h>
#include <string>
#include <windef.h>
#include <windows.h>
#include <winnt.h>
#include <ddeml.h>
#include <shellapi.h>
#include <cstdio>

#include "hook_utils.cpp"

typedef unsigned __int64 QWORD;

// ---------------------------------------------------------------------------------------------- //
// Utils ---------------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //

void
Serialize(void *val, size_t *buffer_head, uint8_t *buffer, size_t size) {
    uint8_t *byte_ptr = (uint8_t *)(val);

    for (size_t i = 0; i < size; i++) {

        if (BUFFER_SIZE <= *buffer_head) {
            LOG("Buffer size exceeded!, terminating");
            exit(1);
        }

        buffer[(*buffer_head)] = byte_ptr[i];
        (*buffer_head)++;
    }

#if 0
    HookBuffer[HookBufferHead] = 0x1E;
    HookBufferHead++;
#endif
}


inline void
StrCpy(char *s) {
    Serialize((void *)s, &HookBufferHead, HookBuffer, strlen(s));
    HookBuffer[HookBufferHead] = '\0';
    HookBufferHead++;
}

void
InitHookCall(char *id) {
    // call or ret
    uint8_t call_id = HOOK_CALL_ID;
    Serialize(&call_id, &HookBufferHead, HookBuffer, sizeof(call_id));

    // depth
    Serialize(&GlobalCallDepth, &HookBufferHead, HookBuffer, sizeof(GlobalCallDepth));

    // func name/id
    StrCpy(id);
}

void
InitHookRet(char *id) {
    // call or ret
    uint8_t ret_id = HOOK_RET_ID;
    Serialize(&ret_id, &HookBufferHead, HookBuffer, sizeof(ret_id));

    // depth
    Serialize(&GlobalCallDepth, &HookBufferHead, HookBuffer, sizeof(GlobalCallDepth));

    // timing
    Serialize(&TimeElapsed, &HookBufferHead, HookBuffer, sizeof(TimeElapsed));

    // func name/id
    StrCpy(id);
}

inline void
BOIL_int8(int8_t val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(int8_t));
}

inline void
BOIL_int16(int16_t val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(int16_t));
}

inline void
BOIL_int32(int32_t val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(int32_t));
}

inline void
BOIL_int64(int64_t val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(int64_t));
}

inline void
BOIL_uint8(uint8_t val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(uint8_t));
}

inline void
BOIL_uint16(uint16_t val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(uint16_t));
}

inline void
BOIL_uint32(uint32_t val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(uint32_t));
}

inline void
BOIL_uint64(uint64_t val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(uint64_t));
}

inline void
BOIL_float32(float val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(float));
}

inline void
BOIL_float64(double val) {
    Serialize(&val, &HookBufferHead, HookBuffer, sizeof(double));
}

// check for nullptr -------------------------------------------------------------- //
// template <typename T>
// T
// inspect(T *ptr) {
//     if (ptr == nullptr) {
//         return T{};
//     }
//
//     return *ptr;
// }

// ---------------------------------------------------------------------------------------------- //
// Win32 value copy to buffer ------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //

// Forward declaration for dependancy resolution ------------------------------------------------ //

// std::wstring BOIL_WCHAR(WCHAR val);
// std::string BOIL_CCHAR(CCHAR val);
// std::string BOIL_CHAR(CHAR val);

std::string BOIL_HANDLE(HANDLE val);

// ---------------------------------------------------------------------------------------------- //

// with A
void
BOIL_ATOM(ATOM val) {
    BOIL_uint16(val);
}

// with B
void
BOIL_BOOL(BOOL val) {
    BOIL_int32(val);
}

void
BOIL_BOOLEAN(BOOLEAN val) {
    BOIL_uint8(val);
}

void
BOIL_BYTE(BYTE val) {
    BOIL_uint8(val);
}

// with C
void
BOIL_CCHAR(CCHAR val) {
    BOIL_int8(val);
}

void
BOIL_CHAR(CHAR val) {
    BOIL_int8(val);
}

void
BOIL_COLORREF(COLORREF val) {
    BOIL_uint32(val);
}

/*
// with D
void
BOIL_DWORD(DWORD val) {
    return _hexify(val);
}

void
BOIL_DWORDLONG(DWORDLONG val) {
    return hexify(val);
}

void
BOIL_DWORD_PTR(DWORD_PTR val) {
    return hexify(val);
}

void
BOIL_DWORD32(DWORD32 val) {
    return hexify(val);
}

void
BOIL_DWORD64(DWORD64 val) {
    return hexify(val);
}

// with F
void
BOIL_FLOAT(FLOAT val) {
    return std::to_string(val);
}

// with H
void
BOIL_HANDLE(HANDLE val) {
    con_to_byteP((void *)&val, &HookBufferHead, HookBuffer);
    delimiter(&HookBufferHead);
    return "";
}

void
BOIL_HACCEL(HACCEL val) {
    return BOIL_HANDLE(val);
}

void
BOIL_HALF_PTR(HALF_PTR val) {
    return hexify(static_cast<uintptr_t>(val));
}

void
BOIL_HBITMAP(HBITMAP val) {
    return BOIL_HANDLE(val);
}

void
BOIL_HBRUSH(HBRUSH val) {
    return BOIL_HANDLE(val);
}

void
BOIL_HCOLORSPACE(HCOLORSPACE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HCONV(HCONV val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HCONVLIST(HCONVLIST val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HDC(HDC val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HDDEDATA(HDDEDATA val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HDESK(HDESK val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HDROP(HDROP val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HDWP(HDWP val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HENHMETAFILE(HENHMETAFILE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HFONT(HFONT val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HGDIOBJ(HGDIOBJ val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HGLOBAL(HGLOBAL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HHOOK(HHOOK val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HICON(HICON val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HINSTANCE(HINSTANCE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HKEY(HKEY val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HKL(HKL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HLOCAL(HLOCAL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HMENU(HMENU val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HMETAFILE(HMETAFILE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HPALETTE(HPALETTE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HPEN(HPEN val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HRGN(HRGN val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HRSRC(HRSRC val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HSZ(HSZ val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}
*/

void
BOIL_HWND(HWND val) {
	BOIL_uint64((uint64_t)val);
}

/*
void
BOIL_SC_HANDLE(SC_HANDLE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

// void BOIL_SERVICE_STATUS_HANDLE(SERVICE_STATUS_HANDLE val) {
//     return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
// }

void
BOIL_HCURSOR(HCURSOR val) {
    return BOIL_HICON(val);
}

void
BOIL_HFILE(HFILE val) {
    return hexify(static_cast<int32_t>(val));
}

void
BOIL_HMODULE(HMODULE val) {
    return BOIL_HINSTANCE(val);
}

void
BOIL_HRESULT(HRESULT val) {
    return hexify(static_cast<uintptr_t>(val));
}

void
BOIL_HMONITOR(HMONITOR val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

void
BOIL_HWINSTA(HWINSTA val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

// with I
void
BOIL_INT(INT val) {
    return hexify(val);
}

void
BOIL_INT8(INT8 val) {
    return hexify(val);
}

void
BOIL_INT16(INT16 val) {
    return hexify(val);
}
*/

void
BOIL_INT32(INT32 val) {
	BOIL_int32(val);
}

/*
void
BOIL_INT64(INT64 val) {
    return hexify(val);
}

void
BOIL_INT_PTR(INT_PTR val) {
    return _hexify(val);
}

// with L
void
BOIL_LANGID(LANGID val) {
    return hexify(val);
}

void
BOIL_LCID(LCID val) {
    return BOIL_DWORD(val);
}

void
BOIL_LCTYPE(LCTYPE val) {
    return BOIL_DWORD(val);
}

void
BOIL_LGRPID(LGRPID val) {
    return BOIL_DWORD(val);
}

void
BOIL_LPCOLORREF(LPCOLORREF val) {
    return BOIL_DWORD(inspect(val));
}

void
BOIL_LPDWORD(LPDWORD val) {
    return BOIL_DWORD(inspect(val));
}

void
BOIL_LONG(LONG val) {
    return hexify(val);
}

void
BOIL_LONGLONG(LONGLONG val) {
    return hexify(val);
}

void
BOIL_LONG_PTR(LONG_PTR val) {
    return hexify(val);
}

void
BOIL_LONG32(LONG32 val) {
    return hexify(val);
}

void
BOIL_LONG64(LONG64 val) {
    return hexify(val);
}

void
BOIL_LPARAM(LPARAM val) {
    return BOIL_LONG_PTR(val);
}

void
BOIL_LPBOOL(LPBOOL val) {
    return BOIL_BOOL(inspect(val));
}

void
BOIL_LPBYTE(LPBYTE val) {
    return BOIL_BYTE(inspect(val));
}
*/

void
BOIL_LPCSTR(LPCSTR val) {
	StrCpy((char *)val);
}

/*
// std::wstring
// BOIL_LPCWSTR(LPCWSTR val) {
//     std::wstring result;
//     while (*val != '\0') {
//         result += BOIL_WCHAR(inspect(val));
//         ++val;
//     }
//     return result;
// }

// #ifdef UNICODE
// void BOIL_LPCTSTR(LPCTSTR val){
//     return BOIL_LPCWSTR(val);
// }
// #else
// void BOIL_LPCTSTR(LPCTSTR val){
//     return BOIL_LPCSTR(val);
// }
// #endif


void
BOIL_LPCVOID(LPCVOID val) {
    return hexify(reinterpret_cast<uintptr_t>(val));
}

void
BOIL_LPHANDLE(LPHANDLE val) {
    return BOIL_HANDLE(inspect(val));
}

void
BOIL_LPINT(LPINT val) {
    return hexify(inspect(val));
}

void
BOIL_LPLONG(LPLONG val) {
    return hexify(inspect(val));
}

void
BOIL_LPSTR(LPSTR val) {
    void result;
    while (*val) {
        result += BOIL_CHAR(inspect(val));
        ++val;
    }
    return result;
}

// std::wstring
// BOIL_LPWSTR(LPWSTR val) {
//     std::wstring result;
//     while (*val != L'\0') {
//         result += BOIL_WCHAR(inspect(val));
//         ++val;
//     }
//     return result;
// }

// void BOIL_LPTSTR( LPTSTR val) {
//     return BOIL_LPWSTR(val);
// }

void
BOIL_LPVOID(LPVOID val) {
    return hexify(reinterpret_cast<uintptr_t>(val));
}

void
BOIL_LPWORD(LPWORD val) {
    return hexify(inspect(val));
}

void
BOIL_LRESULT(LRESULT val) {
    return BOIL_LONG_PTR(val);
}

// // with W
// std::wstring
// BOIL_WCHAR(WCHAR val) {
//     std::wstring str(1, val);
//     return str;
// }

void
BOIL_WORD(WORD val) {
    return hexify(val);
}

void
BOIL_WPARAM(WPARAM val) {
    return hexify(val);
}

// with P
void
BOIL_PBOOL(PBOOL val) {
    return BOIL_BOOL(inspect(val));
}

void
BOIL_PBOOLEAN(PBOOLEAN val) {
    return BOIL_BOOLEAN(inspect(val));
}

void
BOIL_PBYTE(PBYTE val) {
    return BOIL_BYTE(inspect(val));
}

void
BOIL_PCHAR(PCHAR val) {
    return BOIL_CHAR(inspect(val));
}

void
BOIL_PCSTR(PCSTR val) {
    void result;
    while (*val) {
        result += BOIL_CHAR(inspect(val));
        ++val;
    }
    return result;
}

// #ifdef UNICODE
// void BOIL_PCTSTR(PCTSTR val) {
//     return BOIL_LPCWSTR(val);  // For Unicode, treat as LPCWSTR
// }
// #else
// void BOIL_PCTSTR(PCTSTR val) {
//     return BOIL_LPCSTR(val);  // For ANSI, treat as LPCSTR
// }
// #endif


// std::wstring
// BOIL_PCWSTR(PCWSTR val) {
//     std::wstring result;
//     while (*val != L'\0') {
//         result += BOIL_WCHAR(inspect(val));
//         ++val;
//     }
//     return result;
// }

void
BOIL_PDWORD(PDWORD val) {
    return BOIL_DWORD(inspect(val));
}

void
BOIL_PDWORDLONG(PDWORDLONG val) {
    return BOIL_DWORDLONG(inspect(val));
}

void
BOIL_PDWORD_PTR(PDWORD_PTR val) {
    return BOIL_DWORD_PTR(inspect(val));
}

void
BOIL_PDWORD32(PDWORD32 val) {
    return BOIL_DWORD32(inspect(val));
}

void
BOIL_PDWORD64(PDWORD64 val) {
    return BOIL_DWORD64(inspect(val));
}

void
BOIL_PFLOAT(PFLOAT val) {
    return BOIL_FLOAT(inspect(val));
}

void
BOIL_PHALF_PTR(PHALF_PTR val) {
    return BOIL_HALF_PTR(inspect(val));
}

void
BOIL_PHANDLE(PHANDLE val) {
    return BOIL_HANDLE(inspect(val));
}

void
BOIL_PHKEY(PHKEY val) {
    return BOIL_HKEY(inspect(val));
}

void
BOIL_PINT(PINT val) {
    return BOIL_INT(inspect(val));
}

void
BOIL_PINT_PTR(PINT_PTR val) {
    return BOIL_INT_PTR(inspect(val));
}

// void BOIL_PINT8(PINT8 val){
//     return BOIL_INT8(inspect(val));
// }

// void BOIL_PINT16(PINT16 val){
//     return BOIL_INT16(inspect(val));
// }

void
BOIL_PINT32(PINT32 val) {
    return BOIL_INT32(inspect(val));
}

void
BOIL_PINT64(PINT64 val) {
    return BOIL_INT64(inspect(val));
}

void
BOIL_PLCID(PLCID val) {
    return BOIL_PDWORD(val);
}

void
BOIL_PLONG(PLONG val) {
    return BOIL_LONG(inspect(val));
}

void
BOIL_PLONGLONG(PLONGLONG val) {
    return BOIL_LONGLONG(inspect(val));
}

void
BOIL_PLONG_PTR(PLONG_PTR val) {
    return BOIL_LONG_PTR(inspect(val));
}

void
BOIL_PLONG32(PLONG32 val) {
    return BOIL_LONG32(inspect(val));
}

void
BOIL_PLONG64(PLONG64 val) {
    return BOIL_LONG64(inspect(val));
}


void
BOIL_QWORD(QWORD val) {
    return hexify(val);
}


// with S

void
BOIL_SC_LOCK(SC_LOCK val) {
    return BOIL_LPVOID(val);
}


void
BOIL_SHORT(SHORT val) {
    return hexify(val);
}

void
BOIL_SIZE_T(SIZE_T val) {
    return hexify(val);
}

void
BOIL_SSIZE_T(SSIZE_T val) {
    return BOIL_LONG_PTR(val);
}

// with T
//  std::wstring
//  BOIL_TBYTE(TBYTE val) {
//      return BOIL_WCHAR(val);
//  }

// std::wstring
// BOIL_TCHAR(TCHAR val) {
//     return BOIL_WCHAR(val);
// }

// with U

void
BOIL_UCHAR(UCHAR val) {
    void str(1, val);
    return str;
}

void
BOIL_UHALF_PTR(UHALF_PTR val) {
    return hexify(val);
}
*/

void
BOIL_UINT(UINT val) {
	BOIL_uint32(val);
}

/*
void
BOIL_UINT_PTR(UINT_PTR val) {
    return hexify(val);
}

void
BOIL_UINT8(UINT8 val) {
    return hexify(val);
}

void
BOIL_UINT16(UINT16 val) {
    return hexify(val);
}

void
BOIL_UINT32(UINT32 val) {
    return hexify(val);
}

void
BOIL_UINT64(UINT64 val) {
    return hexify(val);
}

void
BOIL_ULONG(ULONG val) {
    return _hexify(val);
}

void
BOIL_ULONGLONG(ULONGLONG val) {
    return hexify(val);
}

void
BOIL_ULONG_PTR(ULONG_PTR val) {
    return hexify(val);
}

void
BOIL_ULONG32(ULONG32 val) {
    return hexify(val);
}

void
BOIL_ULONG64(ULONG64 val) {
    return hexify(val);
}

void
BOIL_USHORT(USHORT val) {
    return hexify(val);
}

void
BOIL_USN(USN val) {
    return BOIL_LONGLONG(val);
}

// with P

void
BOIL_PSHORT(PSHORT val) {
    return BOIL_SHORT(inspect(val));
}

void
BOIL_PSIZE_T(PSIZE_T val) {
    return BOIL_SIZE_T(inspect(val));
}

void
BOIL_PSSIZE_T(PSSIZE_T val) {
    return BOIL_SSIZE_T(inspect(val));
}

void
BOIL_PSTR(PSTR val) {
    void result;
    while (*val) {
        result += BOIL_CHAR(inspect(val));
        ++val;
    }
    return result;
}

// void
// BOIL_PTBYTE(PTBYTE val) {
//     return BOIL_TBYTE(inspect(val));
// }

// void
// BOIL_PTCHAR(PTCHAR val) {
//     return BOIL_TCHAR(inspect(val));
// }

void
BOIL_PTSTR(PTSTR val) {
    void result;
    while (*val) {
        result += BOIL_CHAR(inspect(val));
        ++val;
    }
    return result;
}

void
BOIL_PUCHAR(PUCHAR val) {
    return BOIL_UCHAR(inspect(val));
}

void
BOIL_PUHALF_PTR(PUHALF_PTR val) {
    return BOIL_UHALF_PTR(inspect(val));
}

void
BOIL_PUINT(PUINT val) {
    return BOIL_UINT(inspect(val));
}

void
BOIL_PUINT_PTR(PUINT_PTR val) {
    return BOIL_UINT_PTR(inspect(val));
}

// void BOIL_PUINT8(PUINT8 val){
//     return BOIL_UINT8(inspect(val));
// }

// void BOIL_PUINT16(PUINT16 val){
//     return BOIL_UINT16(inspect(val));
// }

void
BOIL_PUINT32(PUINT32 val) {
    return BOIL_UINT32(inspect(val));
}

void
BOIL_PUINT64(PUINT64 val) {
    return BOIL_UINT64(inspect(val));
}

void
BOIL_PULONG(PULONG val) {
    return BOIL_ULONG(inspect(val));
}

void
BOIL_PULONGLONG(PULONGLONG val) {
    return BOIL_ULONGLONG(inspect(val));
}

void
BOIL_PULONG_PTR(PULONG_PTR val) {
    return BOIL_ULONG_PTR(inspect(val));
}

void
BOIL_PULONG32(PULONG32 val) {
    return BOIL_ULONG32(inspect(val));
}

void
BOIL_PULONG64(PULONG64 val) {
    return BOIL_ULONG64(inspect(val));
}

void
BOIL_PUSHORT(PUSHORT val) {
    return BOIL_USHORT(inspect(val));
}

void
BOIL_PVOID(PVOID val) {
    return hexify(reinterpret_cast<uintptr_t>(val));
}

// std::wstring
// BOIL_PWCHAR(PWCHAR val) {
//     return BOIL_WCHAR(inspect(val));
// }

void
BOIL_PWORD(PWORD val) {
    return BOIL_WORD(inspect(val));
}

// std::wstring
// BOIL_PWSTR(PWSTR val) {
//     std::wstring result;
//     while (*val) {
//         result += BOIL_WCHAR(inspect(val));
//         ++val;
//     }
//     return result;
// }
*/

#if 0
int main() {

    int a = 10;
    int * intptr = &a;
    void * val = &a;

    const char* str;
    str = "Hello! from buffer";
    size_t size = strlen(str) ;

    allocate_buffer();

    BOIL_HANDLE(val);
    BOIL_UINT((uint32_t)a);
    BOIL_LPCSTR(str);

    printf("address: %p\n", &a);
    printf("bufferhead: %d\n", bufferhead);
    for(size_t i = 0; i < bufferhead; i++){
        if(bytebuffer[i] == 0x01E) printf("%c ", '|');
        else
            printf("%x ", bytebuffer[i]);
    }

    free_buffer();

    return 0;
}
#endif

// ---------------------------------------------------------------------------------------------- //
#endif
