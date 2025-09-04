#ifndef BASE_LOGGER_H
#define BASE_LOGGER_H
// Logger Overloads for all windows types ------------------------------------------------------- //

// #include <windows.h>
#include <cstdint>

#include <basetsd.h>
#include <string>
#include <windef.h>
#include <winnt.h>
#include <ddeml.h>
#include <cstdio>
#include <sstream>

static std::ostringstream oss;

// example for structure overload
// std::ostream& operator<<(std::ostream& os, const POINT& pt) {
//     os << "point{\n"
//        << "    x: " << pt.x << "\n"
//        << "    y: " << pt.y << "\n"
//        << "}";
//     return os;
// }

// AN EXAPLE OF WHRE ULONGLONG CAN BE DIRECTLY PROVIDED TO OSTRINGSTREAM NO NEED TO OVERLOAD

// std::ostringstream& operator<<(std::ostringstream& os, const ULONGLONG& val) {
//     os << val;
//     return os;
// }
//
// // APIENTRY and CALLBACK are calling conventions (macros), no overload needed
// // BOOL print TRUE/FALSE instead of 0/1

// with A

std::string WinToStr(ATOM val) {
    char buffer[7]; // enough for 4 hex digits + "0x" + null terminator
    snprintf(buffer, sizeof(buffer), "0x%04X", static_cast<unsigned int>(val));
    return std::string("Atom: ") + buffer;
}
// with B

std::string
WinToStr(BOOL val) {
    std::string result = val ? "TRUE" : "FALSE";
    return result;
}

std::string WinToStr(BOOLEAN val) {
    std::string result = val ? "TRUE" : "FALSE";
    return result;
}

std::string WinToStr(BYTE val) {
    std::string result = std::to_string(reinterpret_cast<unsigned char> (val));
    return result;
}

// with C

std::string WinToStr(CCHAR val){
    std::string result = std::to_string(val);
    return result;
}

std::string WinToStr(CHAR val){
    std::string result = std::to_string(val);
    return result;
}

std::string WinToStr(COLORREF val) {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "0x%08X", val); 
    return std::string("COLORREF: ") + buffer;
}

// with D
std::string WinToStr(DWORD val) {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "0x%08X", val);
    return std::string("DWORD: ") + buffer;
}

std::string WinToStr(DWORDLONG val) {
    char buffer[19];
    snprintf(buffer, sizeof(buffer), "0x%08X", val);
    return std::string("DWORDLONG: ") + buffer;
}

std::string WinToStr(DWORD_PTR val) {
    oss << "DWORD_PTR: 0x" << std::hex << std::uppercase << static_cast<uintptr_t>(val);
    return oss.str().c_str(); 
    oss.str(""); oss.clear();
}

// ---------------------------xxxxx
// std::ostringstream &
// operator<<(std::ostringstream &os, HWND val) {
//     std::string s;
//     s = std::to_string(reinterpret_cast<uintptr_t>(val));
//     os.str(s);
//     return os;
// }


// std::ostringstream& operator<<(std::ostringstream& os, const HANDLE& val) {
//     os << "HANDLE(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HACCEL& val) {
//     os << "HACCEL(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HALF_PTR& val) {
//     os << "HALF_PTR(0x" << std::hex << val << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HBITMAP& val) {
//     os << "HBITMAP(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HBRUSH& val) {
//     os << "HBRUSH(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HCOLORSPACE& val) {
//     os << "HCOLORSPACE(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HCONV& val) {
//     os << "HCONV(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HCONVLIST& val) {
//     os << "HCONVLIST(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HCURSOR& val) {
//     os << "HCURSOR(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HDC& val) {
//     os << "HDC(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HDDEDATA& val) {
//     os << "HDDEDATA(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
//
// std::ostringstream& operator<<(std::ostringstream& os, const HDESK& val) {
//     os << "HDESK(0x" << std::hex << reinterpret_cast<uintptr_t>(val) << ")";
//     return os;
// }
std::string
WinToStr(HWND val) {
    std::string result;
    result = std::to_string(reinterpret_cast<uintptr_t>(val));
    return result;
}

std::string
WinToStr(UINT val) {
    std::string result;
    result = std::to_string(val);
	result = "UINT" + result;
    return result;
}


// ---------------------------------------------------------------------------------------------- //
#endif
