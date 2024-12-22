@echo off
title clean
call C:\PROGRA~2\RADE22\intel_a\code\command\tck_init.bat >nul
call tck_profile V5_6R2012_B22 >nul
call mkRemoveDo -a
pause
