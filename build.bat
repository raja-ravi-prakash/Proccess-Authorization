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
mkdir dist
gcc package/package.c -o package
package
del package.exe
move sys.bat dist
move process.vbs "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup"
del programs.name
echo.
set /p pass=Create Password :
cd package
echo.
echo Password = %pass%
python sha.py %pass%>temp
set /p hash=<temp
echo Hash = %hash%
del temp
setx ronin_h %hash%
setx ronin %__cd__%
cd ..
echo.
echo **build successfull**
echo.
echo Restart to see the changes.