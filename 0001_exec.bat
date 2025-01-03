@rem @set PATH=C:\msys64\mingw64\bin;C:\msys64\usr\local\bin;C:\msys64\usr\bin;C:\msys64\bin;%PATH%
@rem set MSYSTEM=MINGW64
@rem gdb ncurses_test_1000.exe

cd /d %~dp0

@rem ncurses_test_1000.exe

wt.exe %~dp0ncurses_test_1000.exe

pause
