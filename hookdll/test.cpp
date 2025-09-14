#include "win_to_str.cpp"

int
main() {
    // Register all functions
    register_base();

    INT intVal = 0x12345678;
    INT_PTR intPtrVal = 0x23456789;
    INT8 int8Val = 0x34;
    INT16 int16Val = 0x5678;
    INT32 int32Val = 0x56789012;
    INT64 int64Val = 0x6789012345678901;
    LANGID langidVal = 0x7890;
    LCID lcidVal = 0x89012345;
    LCTYPE lctypeVal = 0x90123456;
    LGRPID lgrpidVal = 0xA0123456;
    LONG longVal = 0xB1234567;
    LONGLONG longLongVal = 0xC2345678;
    LONG_PTR longPtrVal = 0xD3456789;
    LONG32 long32Val = 0xE4567890;
    LONG64 long64Val = 0xF5678901;
    LPARAM lparamVal = 0x12345678;

    // BOOL and LPBOOL
    BOOL validBool = TRUE;
    LPBOOL lpboolVal = &validBool;

    // LPBYTE (arbitrary valid address)
    BYTE validByte = 0x56;
    LPBYTE lpbyteVal = &validByte;

    // LPCSTR (string literal)
    LPCSTR lpstrVal = "TestString";

    // LPCTSTR (string literal for both ANSI and Unicode compatibility)
    // LPCTSTR lptstrVal = _T("TestLPCTSTR");

    // LPCVOID (pointer to a valid memory address)
    LPCVOID lpvoidVal = reinterpret_cast<LPCVOID>(0x78901234);

    // LPCWSTR (wide string literal)
    LPCWSTR lpcwstrVal = L"TestLPCWSTR";

    // LPDWORD (pointer to valid DWORD)
    DWORD validDWORD = 12345;
    LPDWORD lpdwordVal = &validDWORD;

    // LPHANDLE (pointer to a valid HANDLE)
    HANDLE validHandle = reinterpret_cast<HANDLE>(0x1234);
    LPHANDLE lphandleVal = &validHandle;

    // LPINT (pointer to valid INT)
    INT validInt = 123;
    LPINT lpintVal = &validInt;

    // LPLONG (pointer to valid LONG)
    LONG validLong = 456;
    LPLONG lplongVal = &validLong;

    // LPSTR (pointer to valid string)
    char validStr[] = "TestString";
    LPSTR lpstr2Val = validStr;

    // LPTSTR (pointer to valid string)
    // TCHAR validTStr[] = _T("TestTCHAR");
    // LPTSTR lptstr2Val = validTStr;

    // LPVOID (pointer to valid object)
    int validIntObj = 10;
    LPVOID lpvoid2Val = &validIntObj;

    // LPWORD (pointer to valid WORD)
    WORD validWord = 100;
    LPWORD lpwordVal = &validWord;

    // LPWSTR (pointer to valid wide string)
    WCHAR validWStr[] = L"TestWideString";
    LPWSTR lpwstrVal = validWStr;

    // PBOOL (pointer to valid BOOL)
    PBOOL pboolVal = &validBool;

    // PBYTE (pointer to valid BYTE)
    PBYTE pbyteVal = &validByte;

    // PCHAR (pointer to valid char)
    PCHAR pcharVal = &validStr[0];

    // PCSTR (pointer to constant string)
    const char *pcstrVal = "ConstString";

    // PCWSTR (pointer to constant wide string)
    const WCHAR *pcwstrVal = L"ConstWideString";

    // PDWORD (pointer to valid DWORD)
    PDWORD pdwordVal = &validDWORD;

    // PFLOAT (pointer to valid float)
    float validFloat = 3.14f;
    PFLOAT pfloatVal = &validFloat;

    // PHANDLE (pointer to valid HANDLE)
    PHANDLE phandleVal = &validHandle;

    // PINT (pointer to valid INT)
    PINT pintVal = &validInt;

    // PINT32 (pointer to valid INT32)
    PINT32 pint32Val = reinterpret_cast<PINT32>(&validInt);

    // PULONG (pointer to valid ULONG)
    ULONG validULong = 6789;
    PULONG pulongVal = &validULong;

    // Pointer types
    LRESULT validLRESULT =
        1234; // LRESULT is typically a type for return values in Windows messages
    PBOOL validPBOOL = new BOOL(true);          // PBOOL is a pointer to a BOOL
    PBOOLEAN validPBOOLEAN = new BOOLEAN(true); // PBOOLEAN is a pointer to a BOOLEAN (True/False)
    PBYTE validPBYTE = new BYTE(255);           // PBYTE is a pointer to a byte
    PCHAR validPCHAR = new CHAR('A');           // PCHAR is a pointer to a character
    PCSTR validPCSTR = "ValidCString";          // PCSTR is a pointer to a constant string (ANSI)
    PCWSTR validPCWSTR = L"ValidWideString";    // PCWSTR is a pointer to a constant wide string
    PDWORD validPDWORD = new DWORD(1024);       // PDWORD is a pointer to DWORD (32-bit unsigned)
    PDWORDLONG validPDWORDLONG =
        new DWORDLONG(9876543210); // PDWORDLONG is a pointer to a DWORDLONG (64-bit unsigned)
    PDWORD_PTR validPDWORD_PTR =
        new DWORD_PTR(456); // PDWORD_PTR is a pointer to DWORD_PTR (pointer-sized unsigned integer)
    PDWORD32 validPDWORD32 =
        new DWORD32(1234); // PDWORD32 is a pointer to DWORD32 (32-bit unsigned)
    PDWORD64 validPDWORD64 =
        new DWORD64(1234567890123456);     // PDWORD64 is a pointer to DWORD64 (64-bit unsigned)
    PFLOAT validPFLOAT = new FLOAT(3.14f); // PFLOAT is a pointer to a FLOAT
    PHALF_PTR validPHALF_PTR = nullptr; // Pointers to half-precision floating-point (use if needed)
    PHANDLE validPHANDLE =
        new HANDLE(reinterpret_cast<HANDLE>(1234)); // PHANDLE is a pointer to a HANDLE
    PHKEY validPHKEY =
        new HKEY(reinterpret_cast<HKEY>(5678)); // PHKEY is a pointer to a HKEY (registry handle)
    PINT validPINT = new INT(42);               // PINT is a pointer to an INT (signed integer)
    PINT_PTR validPINT_PTR =
        new INT_PTR(789); // PINT_PTR is a pointer to an INT_PTR (pointer-sized signed integer)
    PINT32 validPINT32 = new INT32(234); // PINT32 is a pointer to an INT32 (32-bit signed integer)
    PINT64 validPINT64 =
        new INT64(56789012345);        // PINT64 is a pointer to an INT64 (64-bit signed integer)
    PLCID validPLCID = new LCID(1033); // PLCID is a pointer to LCID (locale identifier)
    PLONG validPLONG = new LONG(10);   // PLONG is a pointer to a LONG (signed 32-bit)
    PLONGLONG validPLONGLONG =
        new LONGLONG(10000000000); // PLONGLONG is a pointer to a LONGLONG (signed 64-bit)
    PLONG_PTR validPLONG_PTR =
        new LONG_PTR(500); // PLONG_PTR is a pointer to LONG_PTR (pointer-sized signed integer)
    PLONG32 validPLONG32 =
        new LONG32(999); // PLONG32 is a pointer to LONG32 (32-bit signed integer)
    PLONG64 validPLONG64 =
        new LONG64(456789012345);        // PLONG64 is a pointer to LONG64 (64-bit signed integer)
    PSHORT validPSHORT = new SHORT(300); // PSHORT is a pointer to a SHORT (signed 16-bit)
    PSIZE_T validPSIZE_T =
        new SIZE_T(10000); // PSIZE_T is a pointer to SIZE_T (platform-dependent size type)
    PSSIZE_T validPSSIZE_T =
        new SSIZE_T(-123); // PSSIZE_T is a pointer to SSIZE_T (signed platform-dependent size type)
    PSTR validPSTR =
        new CHAR[6]{'H', 'e', 'l', 'l', 'o', '\0'}; // PSTR is a pointer to an ANSI string
    BYTE *validPTBYTE =
        new BYTE[5]{0x01, 0x02, 0x03, 0x04, 0x05}; // PTBYTE is a pointer to an array of bytes
    CHAR *validPTCHAR =
        new CHAR[3]{'A', 'B', 'C'}; // PTCHAR is a pointer to an array of chars (ANSI or Unicode)
    CHAR *validPTSTR =
        new CHAR[5]{'T', 'e', 's', 't', '\0'}; // PTSTR is a pointer to an ANSI or Unicode string
    PUCHAR validPUCHAR = new UCHAR(0xA);       // PUCHAR is a pointer to an unsigned char
    PUHALF_PTR validPUHALF_PTR =
        nullptr;                      // Pointers to half-precision floating-point (use if needed)
    PUINT validPUINT = new UINT(256); // PUINT is a pointer to a UINT (unsigned 32-bit)
    PUINT_PTR validPUINT_PTR =
        new UINT_PTR(123456); // PUINT_PTR is a pointer to UINT_PTR (pointer-sized unsigned integer)
    PUINT32 validPUINT32 =
        new UINT32(256); // PUINT32 is a pointer to UINT32 (32-bit unsigned integer)
    PUINT64 validPUINT64 =
        new UINT64(9876543210);          // PUINT64 is a pointer to UINT64 (64-bit unsigned integer)
    PULONG validPULONG = new ULONG(789); // PULONG is a pointer to ULONG (32-bit unsigned)
    PULONGLONG validPULONGLONG =
        new ULONGLONG(12345678901234); // PULONGLONG is a pointer to ULONGLONG (64-bit unsigned)
    PULONG_PTR validPULONG_PTR =
        new ULONG_PTR(999); // PULONG_PTR is a pointer to ULONG_PTR (pointer-sized unsigned integer)
    PULONG32 validPULONG32 = new ULONG32(456); // PULONG32 is a pointer to ULONG32 (32-bit unsigned)
    PULONG64 validPULONG64 =
        new ULONG64(654321987654321);        // PULONG64 is a pointer to ULONG64 (64-bit unsigned)
    PUSHORT validPUSHORT = new USHORT(4567); // PUSHORT is a pointer to USHORT (unsigned 16-bit)
    PVOID validPVOID = nullptr;              // PVOID is a pointer to void (generic pointer)
    PWCHAR validPWCHAR = new WCHAR(L'X');    // PWCHAR is a pointer to a wide character
    PWORD validPWORD = new WORD(123);        // PWORD is a pointer to a WORD (unsigned 16-bit)
    SC_HANDLE validSC_HANDLE = reinterpret_cast<SC_HANDLE>(
        0x12345); // SC_HANDLE is a pointer to a service control manager handle
    SC_LOCK validSC_LOCK =
        reinterpret_cast<SC_LOCK>(0x67890); // SC_LOCK is a pointer to a service control lock

    std::cout << "Result for INT: " << BOIL(intVal) << std::endl;
    std::cout << "Result for INT_PTR: " << BOIL(intPtrVal) << std::endl;
    std::cout << "Result for INT8: " << BOIL(int8Val) << std::endl;
    std::cout << "Result for INT16: " << BOIL(int16Val) << std::endl;
    std::cout << "Result for INT32: " << BOIL(int32Val) << std::endl;
    std::cout << "Result for INT64: " << BOIL(int64Val) << std::endl;
    std::cout << "Result for LANGID: " << BOIL(langidVal) << std::endl;
    std::cout << "Result for LCID: " << BOIL(lcidVal) << std::endl;
    std::cout << "Result for LCTYPE: " << BOIL(lctypeVal) << std::endl;
    std::cout << "Result for LGRPID: " << BOIL(lgrpidVal) << std::endl;
    std::cout << "Result for LONG: " << BOIL(longVal) << std::endl;
    std::cout << "Result for LONGLONG: " << BOIL(longLongVal) << std::endl;
    std::cout << "Result for LONG_PTR: " << BOIL(longPtrVal) << std::endl;
    std::cout << "Result for LONG32: " << BOIL(long32Val) << std::endl;
    std::cout << "Result for LONG64: " << BOIL(long64Val) << std::endl;
    std::cout << "Result for LPARAM: " << BOIL(lparamVal) << std::endl;
    std::cout << "Result for LPBOOL: " << BOIL(lpboolVal) << std::endl;
    std::cout << "Result for LPBYTE: " << BOIL(lpbyteVal) << std::endl;
    std::cout << "Result for LPCSTR: " << BOIL(lpstrVal) << std::endl;
    // std::cout << "Result for LPCTSTR: " << BOIL(lptstrVal) << std::endl;
    std::cout << "Result for LPCVOID: " << BOIL(lpvoidVal) << std::endl;
    std::cout << "Result for LPCWSTR: " << BOIL(lpcwstrVal) << std::endl;
    std::cout << "Result for LPDWORD: " << BOIL(lpdwordVal) << std::endl;
    std::cout << "Result for LPHANDLE: " << BOIL(lphandleVal) << std::endl;
    std::cout << "Result for LPINT: " << BOIL(lpintVal) << std::endl;
    std::cout << "Result for LPLONG: " << BOIL(lplongVal) << std::endl; // This line is now valid
    std::cout << "Result for LPSTR: " << BOIL(lpstr2Val) << std::endl;  // This line is now valid
    std::cout << "Result for LPWORD: " << BOIL(lpwordVal) << std::endl;
    // Output the results for each type
    std::cout << "Result for LRESULT: " << BOIL(validLRESULT) << std::endl;
    std::cout << "Result for PBOOL: " << BOIL(validPBOOL) << std::endl;
    std::cout << "Result for PBOOLEAN: " << BOIL(validPBOOLEAN) << std::endl;
    std::cout << "Result for PBYTE: " << BOIL(validPBYTE) << std::endl;
    std::cout << "Result for PCHAR: " << BOIL(validPCHAR) << std::endl;
    std::cout << "Result for PCSTR: " << BOIL(validPCSTR) << std::endl;
    std::cout << "Result for PCWSTR: " << BOIL(validPCWSTR) << std::endl;
    std::cout << "Result for PDWORD: " << BOIL(validPDWORD) << std::endl;
    std::cout << "Result for PDWORDLONG: " << BOIL(validPDWORDLONG) << std::endl;
    std::cout << "Result for PDWORD_PTR: " << BOIL(validPDWORD_PTR) << std::endl;
    std::cout << "Result for PDWORD32: " << BOIL(validPDWORD32) << std::endl;
    std::cout << "Result for PDWORD64: " << BOIL(validPDWORD64) << std::endl;
    std::cout << "Result for PFLOAT: " << BOIL(validPFLOAT) << std::endl;
    std::cout << "Result for PHANDLE: " << BOIL(validPHANDLE) << std::endl;
    std::cout << "Result for PINT: " << BOIL(validPINT) << std::endl;
    std::cout << "Result for PINT32: " << BOIL(validPINT32) << std::endl;
    std::cout << "Result for PLONG: " << BOIL(validPLONG) << std::endl;
    std::cout << "Result for PLONGLONG: " << BOIL(validPLONGLONG) << std::endl;
    std::cout << "Result for PLONG_PTR: " << BOIL(validPLONG_PTR) << std::endl;
    std::cout << "Result for PLONG32: " << BOIL(validPLONG32) << std::endl;
    std::cout << "Result for PLONG64: " << BOIL(validPLONG64) << std::endl;
    std::cout << "Result for PSHORT: " << BOIL(validPSHORT) << std::endl;
    std::cout << "Result for PSTR: " << BOIL(validPSTR) << std::endl;
    std::cout << "Result for PTBYTE: " << BOIL(validPTBYTE) << std::endl;
    std::cout << "Result for PTCHAR: " << BOIL(validPTCHAR) << std::endl;
    std::cout << "Result for PTSTR: " << BOIL(validPTSTR) << std::endl;
    std::cout << "Result for PUINT: " << BOIL(validPUINT) << std::endl;
    std::cout << "Result for PUINT32: " << BOIL(validPUINT32) << std::endl;
    std::cout << "Result for PULONG: " << BOIL(validPULONG) << std::endl;
    std::cout << "Result for PULONGLONG: " << BOIL(validPULONGLONG) << std::endl;
    std::cout << "Result for PULONG_PTR: " << BOIL(validPULONG_PTR) << std::endl;
    std::cout << "Result for PUSHORT: " << BOIL(validPUSHORT) << std::endl;
    std::cout << "Result for PVOID: " << BOIL(validPVOID) << std::endl;
    std::cout << "Result for PWCHAR: " << BOIL(validPWCHAR) << std::endl;
    std::cout << "Result for PWORD: " << BOIL(validPWORD) << std::endl;
    return 0;
}
