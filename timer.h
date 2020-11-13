#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <SDL.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

class timer{
    public:
        timer();
        void DLL_EXPORT fullRes();
        int DLL_EXPORT getPlayTime();
        bool DLL_EXPORT frameLim(int fps);
    private:
        void DLL_EXPORT restart();
        int DLL_EXPORT getDelta();

        int mStart;
        int startT;
};

timer DLL_EXPORT tmInstance();

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
