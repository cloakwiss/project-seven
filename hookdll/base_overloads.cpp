#ifndef BASE_LOGGER_H
#define BASE_LOGGER_H
// String Builder Overloads for all Windows Types ----------------------------------------------- //

#include <cstdint>
#include <string>
#include <basetsd.h>
#include <windef.h>
#include <winnt.h>
#include <ddeml.h>


std::string
BOIL(int val) {
    std::string result = std::to_string(val);
    return result;
}


std::string
BOIL(HWND val) {
    std::string result;
    result = std::to_string(reinterpret_cast<uintptr_t>(val));
    return result;
}

std::string
BOIL(unsigned int val) {
    std::string result;
    result = std::to_string(val);
    result = "UINT" + result;
    return result;
}


std::string
BOIL(const char *val) {
    return val;
}

std::string
BOIL(void *val) {
    return std::to_string(reinterpret_cast<uintptr_t>(val));
}

std::string
BOIL(unsigned long long val) {
    return std::to_string(val);
}

std::string
BOIL(unsigned long val) {
    return std::to_string(val);
}


// ---------------------------------------------------------------------------------------------- //
#endif
