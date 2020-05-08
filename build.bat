@echo off 
set /p no=Enter no.of Programs : 
echo %no% > "programs.name"
echo Enter Program names followed by Extensions
echo.
:loop
    set /p name=Enter Program Name : 
    echo %name%>>programs.name
    set /a no=no-1
    if %no%==0 goto exit
goto loop
:exit
echo.
mkdir dist
gcc package/package.c -o package
gcc package/init.c -o init
package
init
del package.exe
del init.exe
move sys.bat dist
move process.vbs dist
move programs.name dist
cd dist
move process.vbs "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup"
cd ..
echo **build successfull**
echo Restart to see changes...
