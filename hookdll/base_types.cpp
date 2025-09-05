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

std::string hexify(unsigned long val) {
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
    return hexify(val);
}

// with D
std::string 
BOIL_DWORD(DWORD val) {
    return hexify(val);
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
    return hexify(static_cast<uint8_t>(val));
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
    return hexify(static_cast<uint8_t>(val));
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
#endif