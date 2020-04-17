#include "pch.h"
#include "include/chaiscript/chaiscript.hpp"

void wait(int delay)
{
    Sleep(delay);
}

extern "C"
{
    // script:  name of the chaiscript script file being loaded
    // chai:    the chaiscript object
    __declspec(dllexport) void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
    {
        // add stuff to chai context here
        chai->add(chaiscript::fun(&wait), "wait");
        chai->add(chaiscript::fun(&wait), "delay");
        chai->add(chaiscript::fun(&wait), "sleep");
    }

    // script:  name of the chaiscript script file being loaded
    // chai:    the chaiscript object
    __declspec(dllexport) void on_script_loaded(const char* script, chaiscript::ChaiScript* chai)
    {
        // your script has been loaded, you can now interact with the loaded script from the chai object
        // TODO
    }

    // script:  name of the chaiscript script file being loaded
    // chai:    the chaiscript object
    __declspec(dllexport) void on_script_unloaded(const char* script, chaiscript::ChaiScript* chai)
    {
        // your script has been unloaded, you can now cleanup script-specific stuff
        // TODO
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
