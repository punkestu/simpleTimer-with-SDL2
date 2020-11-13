# simpleTimer-with-SDL2
I use SDL2 library to create it

use the SDL2 library when compile it
to compile the main.cpp into DLL file
`g++.exe -Wall -DBUILD_DLL -g -I"your SDL2 directory"\include -c main.cpp -o obj\Debug\main.o`
then
`g++.exe -shared -Wl,--output-def=bin\Debug\libtimer.def -Wl,--out-implib=bin\Debug\libtimer.a -Wl,--dll -L"your SDL2 directory"\lib obj\Debug\main.o  -o bin\Debug\timer.dll -lmingw32 -lSDL2main -lSDL2  -luser32`

