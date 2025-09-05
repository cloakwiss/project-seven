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
}


// Main Abstraction --------------------------------------------- //
template <typename T> 
std::string BOIL(T value) {
    auto it = baseMap.find(std::type_index(typeid(T)));
    if (it != baseMap.end()) {
        return it->second(&value);  
    } else {
        std::cout << "NOT DECLARED!!!";
        return hexify(static_cast<uint8_t>(0));
    }
}
// -------------------------------------------------------------- //
//////////////////////////// END'S HERE //////////////////////////////////////////////


#endif
