#include <Windows.h>

DWORD WINAPI func(void* me) {
    auto proc = GetCurrentProcess();
    auto base = reinterpret_cast<char*>(GetModuleHandleA(nullptr));
    WriteProcessMemory(proc, reinterpret_cast<void*>(base + 0x20C925), "\x90\x90\x90\x90\x90\x90", 6, NULL);
	WriteProcessMemory(proc, reinterpret_cast<void*>(base + 0x20D143), "\x90\x90", 2, NULL);
	WriteProcessMemory(proc, reinterpret_cast<void*>(base + 0x20A563), "\x90\x90", 2, NULL);
	WriteProcessMemory(proc, reinterpret_cast<void*>(base + 0x20A595), "\x90\x90", 2, NULL);
    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(me), 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE mod, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH)
        if (auto h = CreateThread(nullptr, 0, &func, mod, 0, nullptr))
            CloseHandle(h);
    return TRUE;
}
