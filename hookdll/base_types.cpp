#ifndef BASE_TYPES_H
#define BASE_TYPES_H

#include <cstdint>
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <basetsd.h>
#include <string>
#include <windef.h>
#include <windows.h>
#include <winnt.h>
#include <ddeml.h>
#include <cstdio>
#include <sstream>
#include <iostream>

// Hex printing functions ------------------------------------------------------------- //

std::string hexify(long val) {
    char buffer[19];
    snprintf(buffer, sizeof(buffer), "0x%016lX", val);
    return std::string(buffer);
}

std::string hexify(int32_t val) {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "0x%08X", val);  
    return std::string(buffer);
}

std::string hexify(int64_t val) {
    char buffer[19]; 
    snprintf(buffer, sizeof(buffer), "0x%016llX", val);
    return std::string(buffer);
}

std::string hexify(uint8_t val) {
    char buffer[5];  
    snprintf(buffer, sizeof(buffer), "0x%02X", val);
    return std::string(buffer);
}

std::string hexify(uint16_t val) {
    char buffer[7];  
    snprintf(buffer, sizeof(buffer), "0x%04X", val);
    return std::string(buffer);
}

std::string hexify(uint32_t val) {
    char buffer[11];  
    snprintf(buffer, sizeof(buffer), "0x%08X", val);
    return std::string(buffer);
}

std::string hexify(uint64_t val) {
    char buffer[19]; 
    snprintf(buffer, sizeof(buffer), "0x%016X", val);
    return std::string(buffer);
}

std::string _hexify(unsigned long val) {
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

// Functions to handle different types -------------------------------------------- //


// with A
std::string 
BOIL_ATOM(ATOM val) {
    return hexify(val);
}

// with B
std::string 
BOIL_BOOL(BOOL val) {
    return val ? "TRUE" : "FALSE";
}

std::string 
BOIL_BOOLEAN(BOOLEAN val) {
    return val ? "TRUE" : "FALSE";
}

std::string 
BOIL_BYTE(BYTE val) {
    return hexify(val);
}

// with C
std::string 
BOIL_CCHAR(CCHAR val) {
    return std::string(1, val);
}

std::string 
BOIL_CHAR(CHAR val) {
    return std::string(1, val);
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
BOIL_HANDLE(HANDLE val){
    return hexify(reinterpret_cast<uintptr_t>(val));
}

std::string
BOIL_HACCEL(HACCEL val){
    return BOIL_HANDLE(val);
}

std::string
BOIL_HALF_PTR(HALF_PTR val){
    return hexify(static_cast<uintptr_t>(val));
}

std::string
BOIL_HBITMAP(HBITMAP val){
    return BOIL_HANDLE(val);
}

std::string
BOIL_HBRUSH(HBRUSH val){
    return BOIL_HANDLE(val);
}

std::string BOIL_HCOLORSPACE(HCOLORSPACE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HCONV(HCONV val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HCONVLIST(HCONVLIST val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HDC(HDC val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HDDEDATA(HDDEDATA val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HDESK(HDESK val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HDROP(HDROP val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HDWP(HDWP val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HENHMETAFILE(HENHMETAFILE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HFONT(HFONT val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HGDIOBJ(HGDIOBJ val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HGLOBAL(HGLOBAL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HHOOK(HHOOK val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HICON(HICON val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HINSTANCE(HINSTANCE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HKEY(HKEY val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HKL(HKL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HLOCAL(HLOCAL val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HMENU(HMENU val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HMETAFILE(HMETAFILE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HPALETTE(HPALETTE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HPEN(HPEN val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HRGN(HRGN val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HRSRC(HRSRC val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HSZ(HSZ val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HWND(HWND val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_SC_HANDLE(SC_HANDLE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_SERVICE_STATUS_HANDLE(SERVICE_STATUS_HANDLE val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

std::string BOIL_HCURSOR( HCURSOR val) {
    return BOIL_HICON(val);
}

std::string BOIL_HFILE( HFILE val) {
    return hexify(static_cast<int32_t>(val));
}

std::string BOIL_HMODULE( HMODULE val) {
    return BOIL_HINSTANCE(val);
}

std::string BOIL_HRESULT(HRESULT val) {
    return hexify(static_cast<uintptr_t>(val));
}

std::string BOIL_HMONITOR(HMONITOR val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val)); 
}

std::string BOIL_HWINSTA(HWINSTA val) {
    return BOIL_HANDLE(reinterpret_cast<HANDLE>(val));
}

// with I
std::string BOIL_INT( INT val) {
    return hexify(val);
}

std::string BOIL_INT8( INT8 val) {
    return hexify(val);
}

std::string BOIL_INT16( INT16 val) {
    return hexify(val);
}

std::string BOIL_INT32( INT32 val) {
    return hexify(val);
}

std::string BOIL_INT64( INT64 val) {
    return hexify(val);
}

std::string BOIL_INT_PTR( INT_PTR val) {
    return _hexify(val);
}

// with L
std::string BOIL_LANGID( LANGID val) {
    return hexify(val);
}

std::string BOIL_LCID( LCID val) {
    return BOIL_DWORD(val);
}

std::string BOIL_LCTYPE( LCTYPE val) {
    return BOIL_DWORD(val);
}

std::string BOIL_LGRPID( LGRPID val) {
    return BOIL_DWORD(val);
}

std::string BOIL_LPCOLORREF( LPCOLORREF val) {
    return BOIL_DWORD(*val);
}

std::string BOIL_LPDWORD( LPDWORD val) {
    return BOIL_DWORD(*val);
}

std::string BOIL_LONG( LONG val) {
    return hexify(val);
}

std::string BOIL_LONGLONG( LONGLONG val) {
    return hexify(val);
}

std::string BOIL_LONG_PTR( LONG_PTR val) {
    return hexify(val);
}

std::string BOIL_LONG32( LONG32 val) {
    return hexify(val);
}

std::string BOIL_LONG64( LONG64 val) {
    return hexify(val);
}

std::string BOIL_LPARAM( LPARAM val) {
    return BOIL_LONG_PTR(val);
}

std::string BOIL_LPBOOL( LPBOOL val) {
    return BOIL_BOOL(*val);
}

std::string BOIL_LPBYTE( LPBYTE val) {
    return BOIL_BYTE(*val);
}

std::string BOIL_LPCSTR( LPCSTR val) {
    return BOIL_CHAR(*val);
}

std::string BOIL_LPCWSTR( LPCWSTR val) {
    return hexify(*val);
}

std::string BOIL_LPCTSTR( LPCTSTR val) {
    return BOIL_LPCWSTR(val);
}

std::string BOIL_LPCVOID( LPCVOID val) {
    return hexify(reinterpret_cast<uintptr_t>(val));
}

std::string BOIL_LPHANDLE( LPHANDLE val) {
    return BOIL_HANDLE(*val);
}

std::string BOIL_LPINT( LPINT val) {
    return hexify(*val);
}

std::string BOIL_LPLONG( LPLONG val) {
    return hexify(*val);
}

std::string BOIL_LPSTR( LPSTR val) {
    return BOIL_CHAR(*val);
}

std::string BOIL_LPWSTR( LPWSTR val) {
    return std::to_string(*val);
}

std::string BOIL_LPTSTR( LPTSTR val) {
    return BOIL_LPWSTR(val);
}

std::string BOIL_LPVOID( LPVOID val) {
    return hexify(reinterpret_cast<uintptr_t>(val));
}

std::string BOIL_LPWORD( LPWORD val) {
    return hexify(*val);
}

std::string BOIL_LRESULT( LRESULT val) {
    return BOIL_LONG_PTR(val);
}

std::string BOIL_WCHAR( WCHAR val) {
    return hexify(val);
}

std::string BOIL_WORD( WORD val) {
    return hexify(val);
}


#endif