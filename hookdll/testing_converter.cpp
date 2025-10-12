#include <iostream>
#include <cstdint>  // For uint8_t
#include <vector>
int main() {
    // Sample data, a simple integer
    int value = 42;
    
    // Convert the integer value to a void* pointer
    void* voidPtr = &value;
    
    // Cast the void* to uint8_t* to treat it as a pointer to bytes
    uint8_t* bytePtr = reinterpret_cast<uint8_t*>(&voidPtr);

    // Print the memory address in byte format (as individual bytes)
    
    int size = sizeof(bytePtr);
    std::cout << size << std::endl;
    std::cout << "Memory address of voidPtr: ";
    for (int i = 0; i < sizeof(voidPtr); ++i) {
        std::cout << std::hex << (int)bytePtr[i] << " ";  // Print each byte in hexadecimal
    }

    for (size_t i = 0; i < sizeof(voidPtr); ++i) {
        std::cout << std::hex << (int)bytePtr[i] << " ";  // Print each byte in hexadecimal
    }
    
    std::vector<uint8_t> addressBytes(bytePtr, bytePtr + sizeof(voidPtr));

    // Print the memory address stored as bytes (in hexadecimal)
    std::cout << "Memory address of voidPtr as bytes: ";
    for (size_t i = 0; i < addressBytes.size(); ++i) {
        std::cout << std::hex << (int)addressBytes[i] << " ";  // Print each byte in hexadecimal
    }

    std::cout << std::dec << std::endl;  // Switch back to decimal for subsequent outputs
    return 0;
}
