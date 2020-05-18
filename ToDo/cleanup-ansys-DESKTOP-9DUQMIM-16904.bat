@echo off
set LOCALHOST=%COMPUTERNAME%
if /i "%LOCALHOST%"=="DESKTOP-9DUQMIM" (taskkill /f /pid 12892)
if /i "%LOCALHOST%"=="DESKTOP-9DUQMIM" (taskkill /f /pid 16904)

del /F cleanup-ansys-DESKTOP-9DUQMIM-16904.bat
