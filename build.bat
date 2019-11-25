set GXX=%LOCALAPPDATA%\GCC_ARM\9.2.1-2019q4\bin\arm-none-eabi-g++.exe
set AR=%LOCALAPPDATA%\GCC_ARM\9.2.1-2019q4\bin\arm-none-eabi-gcc-ar.exe
set CXXFLAGS=-specs=nosys.specs -fuse-linker-plugin -ggdb -Os -ffunction-sections -fdata-sections -std=gnu++14 -fno-rtti -fno-exceptions

%GXX% -flto -mcpu=cortex-m7 -mthumb %CXXFLAGS% -c wolf.cpp -o wolf.o
%GXX% -flto -mcpu=cortex-m7 -mthumb %CXXFLAGS% -c hornet.cpp -o hornet.o
%GXX% -flto -mcpu=cortex-m7 -mthumb %CXXFLAGS% wolf.o hornet.o -r -static -nodefaultlibs -nostartfiles -o libraryone.o
%AR% -r libraryone.a libraryone.o
%GXX% -flto -mcpu=cortex-m7 -mthumb %CXXFLAGS% -c syscalls.cpp -o syscalls.o
%GXX% -flto -mcpu=cortex-m7 -mthumb %CXXFLAGS% -c main.cpp -o main.o
%GXX% -flto -mcpu=cortex-m7 -mthumb %CXXFLAGS% syscalls.o main.o -r -static -nodefaultlibs -nostartfiles -o librarytwo.o
%AR% -r librarytwo.a librarytwo.o
%GXX% -flto=6 -fuse-linker-plugin -mcpu=cortex-m7 -mthumb %CXXFLAGS% -save-temps -L. -Wl,-gc-sections -Wl,--start-group -lraryone -lrarytwo -Wl,--end-group -o application.elf