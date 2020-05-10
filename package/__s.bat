@echo off
set op=%1
python %ronin%sha.py %op%>temp
set /p hash=<temp
del temp

if %hash%==%ronin_h% goto yes
goto no

:yes
    echo Yes
    goto exit
:no
    echo Wrong
:exit