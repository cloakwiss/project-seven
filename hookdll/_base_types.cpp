#ifndef BASE_TYPES_H
#define BASE_TYPES_H
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
#include "serialized_mem.cpp"

size_t                   size = 0;
typedef unsigned __int64 QWORD;
// Hex printing functions ------------------------------------------------------------- //

template <typename T>
std::string
hexify(T val) {
    // Ensure it's an integral type
    static_assert(std::is_integral<T>::value, "T must be an integral type");

    char   buffer[20];
    size_t type_size = sizeof(val);

    if (type_size <= sizeof(uint8_t)) {
        snprintf(buffer, sizeof(buffer), "0x%02X", static_cast<unsigned int>(val));
    } else if (type_size <= sizeof(uint16_t)) {
        snprintf(buffer, sizeof(buffer), "0x%04X", static_cast<unsigned int>(val));
    } else if (type_size <= sizeof(uint32_t)) {
        snprintf(buffer, sizeof(buffer), "0x%08X", static_cast<unsigned int>(val));
    } else if (type_size <= sizeof(int32_t)) {
        snprintf(buffer, sizeof(buffer), "0x%08X", static_cast<unsigned int>(val));
    } else if (type_size <= sizeof(long)) {
        snprintf(buffer, sizeof(buffer), "0x%08lX", static_cast<unsigned long>(val));
    } else if (type_size <= sizeof(int64_t)) {
        snprintf(buffer, sizeof(buffer), "0x%016llX", static_cast<unsigned long long>(val));
    } else if (type_size <= sizeof(uint64_t)) {
        snprintf(buffer, sizeof(buffer), "0x%016llX", static_cast<unsigned long long>(val));
    } else {
        return "Hexify Error: Unsupported type";
    }

    return std::string(buffer);
}


std::string
_hexify(unsigned long val) {
#if defined(_WIN64) || defined(__x86_64__)
    char buffer[19];
    snprintf(buffer, sizeof(buffer), "0x%016lX", val);
    return std::string(buffer);
#else
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "0x%08lX", val);
    return std::string(buffer);
#endif
}
// check for nullptr -------------------------------------------------------------- //
template <typename T>
T
inspect(T *ptr) {
    if (ptr == nullptr) {
        return T{};
    }

    return *ptr;
}

// Functions to handle different types -------------------------------------------- //

// Forward declaration for dependancy resolution ---------------------------------- //
// std::wstring BOIL_WCHAR(WCHAR val);
//
// std::string BOIL_CCHAR(CCHAR val);
//
// std::string BOIL_CHAR(CHAR val);
//
// std::string BOIL_HANDLE(HANDLE val);
// ------------------------------------------------------------------------------- //

APIENTRY
// with A
std::string
BOIL_ATOM(ATOM val) {
    return (hexify(val));
}

// with B
std::string
BOIL_BOOL(BOOL val) {
    return hexify(val);
}

std::string
BOIL_BOOLEAN(BOOLEAN val) {
    return hexify(val);
}

std::string
BOIL_BYTE(BYTE val) {
    std::string str(1, val);
    return str;
}

// with C
std::string
BOIL_CCHAR(CCHAR val) {
    std::string str(1, val);
    return str;
}

std::string
BOIL_CHAR(CHAR val) {
    std::string str(1, val);
    return str;
}

std::string
BOIL_COLORREF(COLORREF val) {
    return _hexify(val);
}

// with D
std::string
BOIL_DWORD(DWORD val) {
    return _hexify(val);
}

std::string
BOIL_DWORDLONG(DWORDLONG val) {
    return hexify(val);
}

std::string
BOIL_DWORD_PTR(DWORD_PTR val) {
    return hexify(val);
}

std::string
BOIL_DWORD32(DWORD32 val) {
    return hexify(val);
}

std::string
BOIL_DWORD64(DWORD64 val) {
    return hexify(val);
}

// with F
std::string
BOIL_FLOAT(FLOAT val) {
    return std::to_string(val);
}

// with H
std::string
BOIL_HANDLE(HANDLE val) {
    con_to_byteP((void *)&val, &bufferhead, bytebuffer);
    delimiter(&bufferhead);
    return "";
}

std::string
BOIL_HACCEL(HACCEL val) {
    return BOIL_HANDLE(val);
}

std::string
BOIL_HALF_PTR(HALF_PTR val) {
    return hexify(static_cast<uintptr_t>(val));
}

std::string
BOIL_HBITMAP(HBITMAP val) {
    return BOIL_HANDLE(val);
}

std::string
BOIL_HBRUSH(HBRUSH val) {
    return BOIL_HANDLE(val);
}

std::string
BOIL_HCOLORSPACE(HCOLORSPACE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HCONV(HCONV val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HCONVLIST(HCONVLIST val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HDC(HDC val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HDDEDATA(HDDEDATA val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HDESK(HDESK val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HDROP(HDROP val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HDWP(HDWP val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HENHMETAFILE(HENHMETAFILE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HFONT(HFONT val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HGDIOBJ(HGDIOBJ val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HGLOBAL(HGLOBAL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HHOOK(HHOOK val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HICON(HICON val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HINSTANCE(HINSTANCE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HKEY(HKEY val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HKL(HKL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HLOCAL(HLOCAL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HMENU(HMENU val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HMETAFILE(HMETAFILE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HPALETTE(HPALETTE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HPEN(HPEN val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HRGN(HRGN val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HRSRC(HRSRC val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HSZ(HSZ val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HWND(HWND val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_SC_HANDLE(SC_HANDLE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

// std::string BOIL_SERVICE_STATUS_HANDLE(SERVICE_STATUS_HANDLE val) {
//     return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
// }

std::string
BOIL_HCURSOR(HCURSOR val) {
    return BOIL_HICON(val);
}

std::string
BOIL_HFILE(HFILE val) {
    return hexify(static_cast<int32_t>(val));
}

std::string
BOIL_HMODULE(HMODULE val) {
    return BOIL_HINSTANCE(val);
}

std::string
BOIL_HRESULT(HRESULT val) {
    return hexify(static_cast<uintptr_t>(val));
}

std::string
BOIL_HMONITOR(HMONITOR val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string
BOIL_HWINSTA(HWINSTA val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

// with I
std::string
BOIL_INT(INT val) {
    return hexify(val);
}

std::string
BOIL_INT8(INT8 val) {
    return hexify(val);
}

std::string
BOIL_INT16(INT16 val) {
    return hexify(val);
}

std::string
BOIL_INT32(INT32 val) {
    size = sizeof(val);
    con_to_byte(&val, &bufferhead, bytebuffer, &size);
    return "";
}

std::string
BOIL_INT64(INT64 val) {
    return hexify(val);
}

std::string
BOIL_INT_PTR(INT_PTR val) {
    return _hexify(val);
}

// with L
std::string
BOIL_LANGID(LANGID val) {
    return hexify(val);
}

std::string
BOIL_LCID(LCID val) {
    return BOIL_DWORD(val);
}

std::string
BOIL_LCTYPE(LCTYPE val) {
    return BOIL_DWORD(val);
}

std::string
BOIL_LGRPID(LGRPID val) {
    return BOIL_DWORD(val);
}

std::string BOIL_LPCOLORREF( LPCOLORREF val) {
    return BOIL_DWORD(inspect(val));
}

std::string
BOIL_LPDWORD(LPDWORD val) {
    return BOIL_DWORD(inspect(val));
}

std::string
BOIL_LONG(LONG val) {
    return hexify(val);
}

std::string
BOIL_LONGLONG(LONGLONG val) {
    return hexify(val);
}

std::string
BOIL_LONG_PTR(LONG_PTR val) {
    return hexify(val);
}

std::string
BOIL_LONG32(LONG32 val) {
    return hexify(val);
}

std::string
BOIL_LONG64(LONG64 val) {
    return hexify(val);
}

std::string
BOIL_LPARAM(LPARAM val) {
    return BOIL_LONG_PTR(val);
}

std::string
BOIL_LPBOOL(LPBOOL val) {
    return BOIL_BOOL(inspect(val));
}

std::string
BOIL_LPBYTE(LPBYTE val) {
    return BOIL_BYTE(inspect(val));
}

std::string
BOIL_LPCSTR(LPCSTR val) {
    size = strlen(val);
    con_to_byte((void *)val, &bufferhead, bytebuffer, &size);
    delimiter(&bufferhead);
    return "";
}

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
// std::string BOIL_LPCTSTR(LPCTSTR val){
//     return BOIL_LPCWSTR(val);
// }
// #else
// std::string BOIL_LPCTSTR(LPCTSTR val){
//     return BOIL_LPCSTR(val);
// }
// #endif


std::string
BOIL_LPCVOID(LPCVOID val) {
    return hexify(reinterpret_cast<uintptr_t>(val));
}

std::string
BOIL_LPHANDLE(LPHANDLE val) {
    return BOIL_HANDLE(inspect(val));
}

std::string
BOIL_LPINT(LPINT val) {
    return hexify(inspect(val));
}

std::string
BOIL_LPLONG(LPLONG val) {
    return hexify(inspect(val));
}

std::string
BOIL_LPSTR(LPSTR val) {
    std::string result;
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

// std::string BOIL_LPTSTR( LPTSTR val) {
//     return BOIL_LPWSTR(val);
// }

std::string
BOIL_LPVOID(LPVOID val) {
    return hexify(reinterpret_cast<uintptr_t>(val));
}

std::string
BOIL_LPWORD(LPWORD val) {
    return hexify(inspect(val));
}

std::string
BOIL_LRESULT(LRESULT val) {
    return BOIL_LONG_PTR(val);
}

// // with W
// std::wstring
// BOIL_WCHAR(WCHAR val) {
//     std::wstring str(1, val);
//     return str;
// }

std::string
BOIL_WORD(WORD val) {
    return hexify(val);
}

std::string
BOIL_WPARAM(WPARAM val) {
    return hexify(val);
}

// with P
std::string
BOIL_PBOOL(PBOOL val) {
    return BOIL_BOOL(inspect(val));
}

std::string
BOIL_PBOOLEAN(PBOOLEAN val) {
    return BOIL_BOOLEAN(inspect(val));
}

std::string
BOIL_PBYTE(PBYTE val) {
    return BOIL_BYTE(inspect(val));
}

std::string
BOIL_PCHAR(PCHAR val) {
    return BOIL_CHAR(inspect(val));
}

std::string
BOIL_PCSTR(PCSTR val) {
    std::string result;
    while (*val) {
        result += BOIL_CHAR(inspect(val));
        ++val;
    }
    return result;
}

// #ifdef UNICODE
// std::string BOIL_PCTSTR(PCTSTR val) {
//     return BOIL_LPCWSTR(val);  // For Unicode, treat as LPCWSTR
// }
// #else
// std::string BOIL_PCTSTR(PCTSTR val) {
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

std::string
BOIL_PDWORD(PDWORD val) {
    return BOIL_DWORD(inspect(val));
}

std::string
BOIL_PDWORDLONG(PDWORDLONG val) {
    return BOIL_DWORDLONG(inspect(val));
}

std::string
BOIL_PDWORD_PTR(PDWORD_PTR val) {
    return BOIL_DWORD_PTR(inspect(val));
}

std::string
BOIL_PDWORD32(PDWORD32 val) {
    return BOIL_DWORD32(inspect(val));
}

std::string
BOIL_PDWORD64(PDWORD64 val) {
    return BOIL_DWORD64(inspect(val));
}

std::string
BOIL_PFLOAT(PFLOAT val) {
    return BOIL_FLOAT(inspect(val));
}

std::string
BOIL_PHALF_PTR(PHALF_PTR val) {
    return BOIL_HALF_PTR(inspect(val));
}

std::string
BOIL_PHANDLE(PHANDLE val) {
    return BOIL_HANDLE(inspect(val));
}

std::string
BOIL_PHKEY(PHKEY val) {
    return BOIL_HKEY(inspect(val));
}

std::string
BOIL_PINT(PINT val) {
    return BOIL_INT(inspect(val));
}

std::string
BOIL_PINT_PTR(PINT_PTR val) {
    return BOIL_INT_PTR(inspect(val));
}

// std::string BOIL_PINT8(PINT8 val){
//     return BOIL_INT8(inspect(val));
// }

// std::string BOIL_PINT16(PINT16 val){
//     return BOIL_INT16(inspect(val));
// }

std::string
BOIL_PINT32(PINT32 val) {
    return BOIL_INT32(inspect(val));
}

std::string
BOIL_PINT64(PINT64 val) {
    return BOIL_INT64(inspect(val));
}

std::string
BOIL_PLCID(PLCID val) {
    return BOIL_PDWORD(val);
}

std::string
BOIL_PLONG(PLONG val) {
    return BOIL_LONG(inspect(val));
}

std::string
BOIL_PLONGLONG(PLONGLONG val) {
    return BOIL_LONGLONG(inspect(val));
}

std::string
BOIL_PLONG_PTR(PLONG_PTR val) {
    return BOIL_LONG_PTR(inspect(val));
}

std::string
BOIL_PLONG32(PLONG32 val) {
    return BOIL_LONG32(inspect(val));
}

std::string
BOIL_PLONG64(PLONG64 val) {
    return BOIL_LONG64(inspect(val));
}


std::string
BOIL_QWORD(QWORD val) {
    return hexify(val);
}

// -----------------------------------------/*/


// with S

std::string
BOIL_SC_LOCK(SC_LOCK val) {
    return BOIL_LPVOID(val);
}


std::string
BOIL_SHORT(SHORT val) {
    return hexify(val);
}

std::string
BOIL_SIZE_T(SIZE_T val) {
    return hexify(val);
}

std::string
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

std::string
BOIL_UCHAR(UCHAR val) {
    std::string str(1, val);
    return str;
}

std::string
BOIL_UHALF_PTR(UHALF_PTR val) {
    return hexify(val);
}

std::string
BOIL_UINT(UINT val) {
    size = sizeof(UINT);
    con_to_byte((void *)&val, &bufferhead, bytebuffer, &size);
    delimiter(&bufferhead);
    return "";
}

std::string
BOIL_UINT_PTR(UINT_PTR val) {
    return hexify(val);
}

std::string
BOIL_UINT8(UINT8 val) {
    return hexify(val);
}

std::string
BOIL_UINT16(UINT16 val) {
    return hexify(val);
}

std::string
BOIL_UINT32(UINT32 val) {
    return hexify(val);
}

std::string
BOIL_UINT64(UINT64 val) {
    return hexify(val);
}

std::string
BOIL_ULONG(ULONG val) {
    return _hexify(val);
}

std::string
BOIL_ULONGLONG(ULONGLONG val) {
    return hexify(val);
}

std::string
BOIL_ULONG_PTR(ULONG_PTR val) {
    return hexify(val);
}

std::string
BOIL_ULONG32(ULONG32 val) {
    return hexify(val);
}

std::string
BOIL_ULONG64(ULONG64 val) {
    return hexify(val);
}

std::string
BOIL_USHORT(USHORT val) {
    return hexify(val);
}

std::string
BOIL_USN(USN val) {
    return BOIL_LONGLONG(val);
}

// with P

std::string
BOIL_PSHORT(PSHORT val) {
    return BOIL_SHORT(inspect(val));
}

std::string
BOIL_PSIZE_T(PSIZE_T val) {
    return BOIL_SIZE_T(inspect(val));
}

std::string
BOIL_PSSIZE_T(PSSIZE_T val) {
    return BOIL_SSIZE_T(inspect(val));
}

std::string
BOIL_PSTR(PSTR val) {
    std::string result;
    while (*val) {
        result += BOIL_CHAR(inspect(val));
        ++val;
    }
    return result;
}

// std::string
// BOIL_PTBYTE(PTBYTE val) {
//     return BOIL_TBYTE(inspect(val));
// }

// std::string
// BOIL_PTCHAR(PTCHAR val) {
//     return BOIL_TCHAR(inspect(val));
// }

std::string
BOIL_PTSTR(PTSTR val) {
    std::string result;
    while (*val) {
        result += BOIL_CHAR(inspect(val));
        ++val;
    }
    return result;
}

std::string
BOIL_PUCHAR(PUCHAR val) {
    return BOIL_UCHAR(inspect(val));
}

std::string
BOIL_PUHALF_PTR(PUHALF_PTR val) {
    return BOIL_UHALF_PTR(inspect(val));
}

std::string
BOIL_PUINT(PUINT val) {
    return BOIL_UINT(inspect(val));
}

std::string
BOIL_PUINT_PTR(PUINT_PTR val) {
    return BOIL_UINT_PTR(inspect(val));
}

// std::string BOIL_PUINT8(PUINT8 val){
//     return BOIL_UINT8(inspect(val));
// }

// std::string BOIL_PUINT16(PUINT16 val){
//     return BOIL_UINT16(inspect(val));
// }

std::string
BOIL_PUINT32(PUINT32 val) {
    return BOIL_UINT32(inspect(val));
}

std::string
BOIL_PUINT64(PUINT64 val) {
    return BOIL_UINT64(inspect(val));
}

std::string
BOIL_PULONG(PULONG val) {
    return BOIL_ULONG(inspect(val));
}

std::string
BOIL_PULONGLONG(PULONGLONG val) {
    return BOIL_ULONGLONG(inspect(val));
}

std::string
BOIL_PULONG_PTR(PULONG_PTR val) {
    return BOIL_ULONG_PTR(inspect(val));
}

std::string
BOIL_PULONG32(PULONG32 val) {
    return BOIL_ULONG32(inspect(val));
}

std::string
BOIL_PULONG64(PULONG64 val) {
    return BOIL_ULONG64(inspect(val));
}

std::string
BOIL_PUSHORT(PUSHORT val) {
    return BOIL_USHORT(inspect(val));
}

std::string
BOIL_PVOID(PVOID val) {
    return hexify(reinterpret_cast<uintptr_t>(val));
}

// std::wstring
// BOIL_PWCHAR(PWCHAR val) {
//     return BOIL_WCHAR(inspect(val));
// }

std::string
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
