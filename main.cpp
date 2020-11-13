#include "timer.h"

// a sample exported function
timer DLL_EXPORT tmInstance()
{
    timer tm = timer();
    return tm;
}

DLL_EXPORT timer::timer()
{
    fullRes();
}

void DLL_EXPORT timer::fullRes()
{
    restart();
    mStart = SDL_GetTicks();
}

void DLL_EXPORT timer::restart()
{
    startT = SDL_GetTicks();
}

int DLL_EXPORT timer::getDelta()
{
    return SDL_GetTicks() - startT;
}

int DLL_EXPORT timer::getPlayTime()
{
    return SDL_GetTicks() - mStart;
}

bool DLL_EXPORT timer::frameLim(int fps)
{
    bool retVal = false;
    if(getDelta()>=1000/fps){
        restart();
        retVal = true;
    }

    return retVal;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
