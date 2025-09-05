#include "win_to_str.cpp"

int main() {
    // Register all functions
    register_base();

    HACCEL haccel = reinterpret_cast<HACCEL>(0x12345678);
    HBITMAP hbitmap = reinterpret_cast<HBITMAP>(0x23456789);
    HBRUSH hbrush = reinterpret_cast<HBRUSH>(0x34567890);
    HCOLORSPACE hcolorspace = reinterpret_cast<HCOLORSPACE>(0x45678901);
    HCONV hconv = reinterpret_cast<HCONV>(0x56789012);
    HCONVLIST hconvlist = reinterpret_cast<HCONVLIST>(0x67890123);
    HDC hdc = reinterpret_cast<HDC>(0x78901234);
    HDDEDATA hddedata = reinterpret_cast<HDDEDATA>(0x89012345);
    HDESK hdesk = reinterpret_cast<HDESK>(0x90123456);
    HDROP hdrop = reinterpret_cast<HDROP>(0xA0123456);
    HDWP hdwp = reinterpret_cast<HDWP>(0xB1234567);
    HENHMETAFILE henhmfile = reinterpret_cast<HENHMETAFILE>(0xC2345678);
    HFONT hfont = reinterpret_cast<HFONT>(0xD3456789);
    HGDIOBJ hgdiobj = reinterpret_cast<HGDIOBJ>(0xE4567890);
    HGLOBAL hglobal = reinterpret_cast<HGLOBAL>(0xF5678901);
    HHOOK hhook = reinterpret_cast<HHOOK>(0x12345678);
    HICON hicon = reinterpret_cast<HICON>(0x23456789);
    HINSTANCE hinstance = reinterpret_cast<HINSTANCE>(0x34567890);
    HKEY hkey = reinterpret_cast<HKEY>(0x45678901);
    HKL hkl = reinterpret_cast<HKL>(0x56789012);
    HLOCAL hlocal = reinterpret_cast<HLOCAL>(0x67890123);
    HMENU hmenu = reinterpret_cast<HMENU>(0x78901234);
    HMETAFILE hmetafile = reinterpret_cast<HMETAFILE>(0x89012345);
    HPALETTE hpalette = reinterpret_cast<HPALETTE>(0x90123456);
    HPEN hpen = reinterpret_cast<HPEN>(0xA0123456);
    HRGN hrgn = reinterpret_cast<HRGN>(0xB1234567);
    HRSRC hrsrc = reinterpret_cast<HRSRC>(0xC2345678);
    HSZ hsz = reinterpret_cast<HSZ>(0xD3456789);
    HWND hwnd = reinterpret_cast<HWND>(0xE4567890);
    SC_HANDLE schandle = reinterpret_cast<SC_HANDLE>(0xF5678901);
    HFILE hfile = (0xF5678901);
    HMODULE hmodule = reinterpret_cast<HMODULE>(0xF5678901);
    HMONITOR hmonitor = reinterpret_cast<HMONITOR>(0xF5678901);
    //SERVICE_STATUS_HANDLE servicehandle = reinterpret_cast<SERVICE_STATUS_HANDLE>(0x12345678);

    // Print results of calling BOIL for HANDLE-based types
    std::cout << "Result for HACCEL: " << BOIL(haccel) << std::endl;
    std::cout << "Result for HBITMAP: " << BOIL(hbitmap) << std::endl;
    std::cout << "Result for HBRUSH: " << BOIL(hbrush) << std::endl;
    std::cout << "Result for HCOLORSPACE: " << BOIL(hcolorspace) << std::endl;
    std::cout << "Result for HCONV: " << BOIL(hconv) << std::endl;
    std::cout << "Result for HCONVLIST: " << BOIL(hconvlist) << std::endl;
    std::cout << "Result for HDC: " << BOIL(hdc) << std::endl;
    std::cout << "Result for HDDEDATA: " << BOIL(hddedata) << std::endl;
    std::cout << "Result for HDESK: " << BOIL(hdesk) << std::endl;
    std::cout << "Result for HDROP: " << BOIL(hdrop) << std::endl;
    std::cout << "Result for HDWP: " << BOIL(hdwp) << std::endl;
    std::cout << "Result for HENHMETAFILE: " << BOIL(henhmfile) << std::endl;
    std::cout << "Result for HFILE: " << BOIL(hfile) << std::endl;
    std::cout << "Result for HFONT: " << BOIL(hfont) << std::endl;
    std::cout << "Result for HGDIOBJ: " << BOIL(hgdiobj) << std::endl;
    std::cout << "Result for HGLOBAL: " << BOIL(hglobal) << std::endl;
    std::cout << "Result for HHOOK: " << BOIL(hhook) << std::endl;
    std::cout << "Result for HICON: " << BOIL(hicon) << std::endl;
    std::cout << "Result for HINSTANCE: " << BOIL(hinstance) << std::endl;
    std::cout << "Result for HKEY: " << BOIL(hkey) << std::endl;
    std::cout << "Result for HKL: " << BOIL(hkl) << std::endl;
    std::cout << "Result for HLOCAL: " << BOIL(hlocal) << std::endl;
    std::cout << "Result for HMENU: " << BOIL(hmenu) << std::endl;
    std::cout << "Result for HMETAFILE: " << BOIL(hmetafile) << std::endl;
    std::cout << "Result for HMODULE: " << BOIL(hmodule) << std::endl;
    std::cout << "Result for HMONITOR: " << BOIL(hmonitor) << std::endl;
    std::cout << "Result for HPALETTE: " << BOIL(hpalette) << std::endl;
    std::cout << "Result for HPEN: " << BOIL(hpen) << std::endl;
    std::cout << "Result for HRGN: " << BOIL(hrgn) << std::endl;
    std::cout << "Result for HRSRC: " << BOIL(hrsrc) << std::endl;
    std::cout << "Result for HSZ: " << BOIL(hsz) << std::endl;
    std::cout << "Result for HWND: " << BOIL(hwnd) << std::endl;
    std::cout << "Result for SC_HANDLE: " << BOIL(schandle) << std::endl;
    //std::cout << "Result for SERVICE_STATUS_HANDLE: " << BOIL(servicehandle) << std::endl;

    return 0;
}
