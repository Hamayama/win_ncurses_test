@set PATH=C:\msys64\mingw64\bin;C:\msys64\usr\local\bin;C:\msys64\usr\bin;C:\msys64\bin;%PATH%
set MSYSTEM=MINGW64
set LDFLAGS=-L/msys64/mingw64/bin
set LIBS=-lncursesw
set DLL=C:\msys64\mingw64\bin\libncursesw6.dll

cd /d %~dp0

for %%i in (
    ncurses_test_1000
) do (
    gcc -g -O2 -Wall -Wextra -o %%i.exe %%i.c %LDFLAGS% %LIBS%
)

copy %DLL% .

pause
