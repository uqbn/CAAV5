@echo off
title clean
call C:\PROGRA~2\RADE22\intel_a\code\command\tck_init.bat >NUL
call tck_profile V5_6R2012_B22 >NUL
call mkRemoveDo -a
pause
