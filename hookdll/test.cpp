#include "win_to_str.cpp"

int
main() {
    // Register all functions
    register_base();

    LPCSTR lpApplicationName = NULL;  // Application name (NULL)
    LPCSTR lpCommandLine = NULL;      // Command line (NULL)
    BOOL bInheritHandles = FALSE;    // Inherit handles (FALSE)
    DWORD dwCreationFlags = 0;       // Creation flags (0)
    LPCSTR lpCurrentDirectory = NULL; // Current directory (NULL)
    LPVOID lpEnvironment = NULL;      // Environment block (NULL)
    STARTUPINFOA* lpStartupInfo = NULL; // Startup info (NULL)
    PROCESS_INFORMATION* lpProcessInformation = NULL; // Process information (NULL)
    BOOL result = FALSE;  // Result of CreateProcessA (FALSE)


    std::cout << "  LPCSTR: " << BOIL(lpApplicationName) << "\n";
    std::cout << "  LPCSTR: " << BOIL(lpCommandLine) << "\n";
    std::cout << "  BOOL: " << BOIL(bInheritHandles) << "\n";
    std::cout << "  DWORD: " << BOIL(dwCreationFlags);
    std::cout << "  LPCSTR: " << BOIL(lpCurrentDirectory) << "\n";
    std::cout << "  PROCESS_INFORMATION: " << BOIL(lpProcessInformation ) << "\n";

    std::cout << "CreateProcessA returned: \n";
    std::cout << "  LPCSTR: " << BOIL(lpCommandLine) << "\n";
    return 0;
}
