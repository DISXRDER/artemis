#include "pch.h"
#include <Windows.h>

#pragma region DLL_EXPORTS
extern "C" __declspec(dllexport) LRESULT CALLBACK NextHook(int code, WPARAM wParam, LPARAM lParam) {
    return CallNextHookEx(NULL, code, wParam, lParam);
}
#pragma endregion

uintptr_t roblox_base = (uintptr_t)GetModuleHandleA(0);

using print = DWORD64(__cdecl*)(unsigned int type, const char* message, ...);
print roblox_print = reinterpret_cast<print>(roblox_base + 0x27F26A0);


void start() {
    MessageBoxA(0, "printsploit sigma", "", MB_TOPMOST);
    roblox_print(1LL, "hi sigam");
    roblox_print(2LL, "hi sigam");
    roblox_print(3LL, "hi sigam");
    roblox_print(0LL, "hi sigam");

}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        start();

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
