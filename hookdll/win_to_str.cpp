#ifndef BASE_LOGGER_H
#define BASE_LOGGER_H

#include "base_types.cpp"
#include <iostream>
/////////////////////////////// IMP SECTION //////////////////////////////////////////
// Map constructs ----------------------------------------------------------------- //
// BaseMap 
std::unordered_map<std::type_index, std::function<std::string(void*)>> baseMap;

template <typename T> 
static void store(std::string (*func)(T)) {
    baseMap[std::type_index(typeid(T))] = [func](void* arg) -> std::string {
        T* val = static_cast<T*>(arg); 
        if (val) {
            return func(*val); 
        } else {
            return "NULL";
        }
    };
}
// ------------------------------------------------------------------------------- //

void register_base() {
    store(BOIL_BOOL);  
    store(BOIL_ATOM);    
    store(BOIL_CCHAR);   
    store(BOIL_CHAR);    
    store(BOIL_BYTE);
    store(BOIL_BOOLEAN);
    store(BOIL_COLORREF);
    store(BOIL_DWORD);
    store(BOIL_DWORDLONG);
    store(BOIL_DWORD_PTR);
    store(BOIL_DWORD32);
    store(BOIL_DWORD64);
    store(BOIL_FLOAT);
    store(BOIL_HACCEL);  
    store(BOIL_HALF_PTR);  
    store(BOIL_HANDLE);   
    store(BOIL_HBITMAP);   
    store(BOIL_HBRUSH);    
    store(BOIL_HCOLORSPACE);  
    store(BOIL_HCONV);   
    store(BOIL_HCONVLIST);  
    store(BOIL_HCURSOR);   
    store(BOIL_HDC);  
    store(BOIL_HDDEDATA);   
    store(BOIL_HDESK);    
    store(BOIL_HDROP);   
    store(BOIL_HDWP);    
    store(BOIL_HENHMETAFILE);  
    store(BOIL_HFILE);    
    store(BOIL_HFONT);   
    store(BOIL_HGDIOBJ);   
    store(BOIL_HGLOBAL);   
    store(BOIL_HHOOK);   
    store(BOIL_HICON);   
    store(BOIL_HINSTANCE);  
    store(BOIL_HKEY);    
    store(BOIL_HKL);    
    store(BOIL_HLOCAL);    
    store(BOIL_HMENU);    
    store(BOIL_HMETAFILE);   
    store(BOIL_HMODULE);    
    store(BOIL_HMONITOR);    
    store(BOIL_HPALETTE);   
    store(BOIL_HPEN);    
    store(BOIL_HRESULT);   
    store(BOIL_HRGN);    
    store(BOIL_HRSRC);   
    store(BOIL_HSZ);    
    store(BOIL_HWINSTA);    
    store(BOIL_HWND);
    store(BOIL_SC_HANDLE);
    store(BOIL_INT);  
    store(BOIL_INT_PTR);    
    store(BOIL_INT8);   
    store(BOIL_INT16);    
    store(BOIL_INT32);
    store(BOIL_INT64);
    store(BOIL_LANGID);
    store(BOIL_LCID);
    store(BOIL_LCTYPE);
    store(BOIL_LGRPID);
    store(BOIL_LONG);
    store(BOIL_LONGLONG);
    store(BOIL_LONG_PTR);
    store(BOIL_LONG32);
    store(BOIL_LONG64);
    store(BOIL_LPARAM);
    // store(BOIL_LPBOOL);
    store(BOIL_LPBYTE);
    // store(BOIL_LPCOLORREF);
    store(BOIL_LPCSTR);
    // store(BOIL_LPCTSTR);
    store(BOIL_LPCVOID);
    store(BOIL_LPCWSTR);
    store(BOIL_LPDWORD);
    store(BOIL_LPHANDLE);
    store(BOIL_LPINT);
    store(BOIL_LPLONG);
    store(BOIL_LPSTR);
    // store(BOIL_LPTSTR);
    store(BOIL_LPVOID);
    store(BOIL_LPWORD);
    store(BOIL_LPWSTR);
    store(BOIL_LRESULT);
    store(BOIL_PBOOL);
    store(BOIL_PBOOLEAN);
    store(BOIL_PBYTE);
    store(BOIL_PCHAR);
    store(BOIL_PCSTR);
    // store(BOIL_PCTSTR);
    store(BOIL_PCWSTR);
    store(BOIL_PDWORD);
    store(BOIL_PDWORDLONG);
    store(BOIL_PDWORD_PTR);
    store(BOIL_PDWORD32);
    store(BOIL_PDWORD64);
    store(BOIL_PFLOAT);
    store(BOIL_PHALF_PTR);
    store(BOIL_PHANDLE);
    store(BOIL_PHKEY);
    store(BOIL_PINT);
    store(BOIL_PINT_PTR);
    // store(BOIL_PINT8);
    // store(BOIL_PINT16);
    store(BOIL_PINT32);
    store(BOIL_PINT64);
    store(BOIL_PLCID);
    store(BOIL_PLONG);
    store(BOIL_PLONGLONG);
    store(BOIL_PLONG_PTR);
    store(BOIL_PLONG32);
    store(BOIL_PLONG64);
    store(BOIL_PSHORT);
    store(BOIL_PSIZE_T);
    store(BOIL_PSSIZE_T);
    store(BOIL_PSTR);
    store(BOIL_PTBYTE);
    store(BOIL_PTCHAR);
    store(BOIL_PTSTR);
    store(BOIL_PUCHAR);
    store(BOIL_PUHALF_PTR);
    store(BOIL_PUINT);
    store(BOIL_PUINT_PTR);
    // store(BOIL_PUINT8);
    // store(BOIL_PUINT16);
    store(BOIL_PUINT32);
    store(BOIL_PUINT64);
    store(BOIL_PULONG);
    store(BOIL_PULONGLONG);
    store(BOIL_PULONG_PTR);
    store(BOIL_PULONG32);
    store(BOIL_PULONG64);
    store(BOIL_PUSHORT);
    store(BOIL_PVOID);
    store(BOIL_PWCHAR);
    store(BOIL_PWORD);
    store(BOIL_PWSTR);
    // store(BOIL_QWORD);
    store(BOIL_SC_HANDLE);
    store(BOIL_SC_LOCK);
    // store(BOIL_SERVICE_STATUS_HANDLE);
    store(BOIL_SHORT);
    store(BOIL_SIZE_T);
    store(BOIL_SSIZE_T);
    store(BOIL_TBYTE);
    store(BOIL_TCHAR);
    store(BOIL_UCHAR);
    store(BOIL_UHALF_PTR);
    store(BOIL_UINT);
    store(BOIL_UINT_PTR);
    store(BOIL_UINT8);
    store(BOIL_UINT16);
    store(BOIL_UINT32);
    store(BOIL_UINT64);
    store(BOIL_ULONG);
    store(BOIL_ULONGLONG);
    store(BOIL_ULONG_PTR);
    store(BOIL_ULONG32);
    store(BOIL_ULONG64);
    store(BOIL_USHORT);
    store(BOIL_USN);
    store(BOIL_WCHAR);
    store(BOIL_WORD);
    store(BOIL_WPARAM);
}


// Main Abstraction --------------------------------------------- //
template <typename T> 
std::string BOIL(T value) {
    std::cout << value << std::endl;
    auto it = baseMap.find(std::type_index(typeid(T)));
    if (it != baseMap.end()) {
        std::cout << "found" << "\n";
        return it->second(&value);  
    } else {
        std::cout << "NOT DECLARED!!!";
        return hexify(static_cast<uint8_t>(0));
    }
}
// -------------------------------------------------------------- //
//////////////////////////// END'S HERE //////////////////////////////////////////////


#endif
