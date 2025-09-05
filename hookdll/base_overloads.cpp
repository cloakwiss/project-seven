#ifndef BASE_LOGGER_H
#define BASE_LOGGER_H
// Logger Overloads for all windows types ------------------------------------------------------- //

// #include <windows.h>
#include <cstdint>
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <basetsd.h>
#include <string>
#include <windef.h>
#include <winnt.h>
#include <ddeml.h>
#include <cstdio>
#include <sstream>

std::unordered_map<std::type_index, std::function<void(void*)>> baseMap;

// Hex printing functions ------------------------------------------------------------------------- //

// Overload for uint8_t (1 byte)
std::string hexify(uint8_t val) {
    char buffer[5];  
    snprintf(buffer, sizeof(buffer), "0x%02X", val);
    return buffer;
}

// Overload for uint16_t (2 bytes)
std::string hexify(uint16_t val) {
    char buffer[7];  
    snprintf(buffer, sizeof(buffer), "0x%04X", val);
    return buffer;
}

// Overload for uint32_t (4 bytes)
std::string hexify(uint32_t val) {
    char buffer[11];  
    snprintf(buffer, sizeof(buffer), "0x%08X", val);
    return buffer;
}

// Overload for uint64_t (8 bytes)
std::string hexify(uint64_t val) {
    char buffer[19]; 
    snprintf(buffer, sizeof(buffer), "0x%016X", val);
    return buffer;
}

// Overload for unsigned long (typically 4 bytes on 32-bit systems and 8 bytes on 64-bit systems)
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
// ------------------------------------------------------------------------------------------------ //


// with A
std::string 
BOIL_ATOM(ATOM val) {
    return "Atom: " + hexify(val);
}

// with B
std::string
BOIL_BOOL(BOOL val) {
    std::string result = val ? "TRUE" : "FALSE";
    return result;
}

std::string 
BOIL_BOOLEAN(BOOLEAN val) {
    std::string result = val ? "TRUE" : "FALSE";
    return result;
}

std::string 
BOIL_BYTE(BYTE val) {
    std::string result = " BYTE: " + hexify(val);
    return result;
}

// with C

std::string 
BOIL_CCHAR(CCHAR val){
    std::string result = std::string(1, val);
    return result;
}

std::string 
BOIL_CHAR(CHAR val){
    std::string result = std::string(1, val);
    return result;
}

template <typename T>
void store(std::string (*func)(T)) { // adding funtion to baseMap
    baseMap[type_index(typeid(T))] = [func](void* arg) {
        func(*static_cast<T*>(arg));
    };
}

/* Register function

    CODE (yet to come)

*/

template <typename T>
std::string BOIL(T value) {
    
    // Check if the type is in the map and call the corresponding function
    auto it = baseMap.find(type_index(typeid(T)));
    if (it != baseMap.end()) {
        return it->second(&value);
    } else {
        return hexify(0);
    }
}



// std::string 
// BOIL(COLORREF val) {
//     return "COLORREF: " + hexify(val);
// }

// // with D
// std::string 
// BOIL(DWORD val) {
//     return std::string("DWORD: ") + hexify(val);
// }

// std::string 
// BOIL(DWORDLONG val) {
//     return std::string("DWORDLONG: ") + hexify(val);
// }

// std::string 
// BOIL(DWORD_PTR val) {
//     return " DWORD_PTR: " + hexify(val);
// }

// std::string 
// BOIL(DWORD32 val) {
//     return " DWORD32: " + hexify(val);
// }

// std::string 
// BOIL(DWORD64 val) {
//     return " DWORD64: " + hexify(val);
// }

// std::string 
// BOIL(FLOAT val) {
//     return " FLOAT: " + std::to_string(val);
// }


int main() {
    // Initialize the function map with different types
    store(BOIL_BOOL);
    store(BOIL_ATOM);
    store(BOIL_CCHAR);
    store(BOIL_CHAR);

    BYTE bval = 255;
    BOOLEAN val = true;
    // Test dynamic function calling
    BOIL(bval);           // Calls BOIL_BOOL
    BOIL('B');             // Calls BOIL_INT
    BOIL(val);          // Calls BOIL_FLOAT
    BOIL('A');// Calls BOIL_STRING

    return 0;
}
// ---------------------------------------------------------------------------------------------- //
#endif
