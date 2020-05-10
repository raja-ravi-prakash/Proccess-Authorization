@echo off
rmdir /q/s dist
reg delete "HKCU\Environment" /v ronin_h /f
del "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup\process.vbs"
echo **clean successfull** 