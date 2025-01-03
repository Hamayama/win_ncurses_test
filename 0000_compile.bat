@set PATH=C:\msys64\mingw64\bin;C:\msys64\usr\local\bin;C:\msys64\usr\bin;C:\msys64\bin;%PATH%
set MSYSTEM=MINGW64
set LDFLAGS=-L/msys64/mingw64/bin
set LIBS=-lncursesw
set DLL=C:\msys64\mingw64\bin\libncursesw6.dll
set PROG1=ncurses_test_1000

cd /d %~dp0

gcc -g -O2 -Wall -Wextra -o %PROG1%.exe %PROG1%.c %LDFLAGS% %LIBS%

copy %DLL% .

pause
