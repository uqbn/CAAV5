@echo off
title build
call C:\PROGRA~2\RADE22\intel_a\code\command\tck_init.bat >NUL
call tck_profile V5_6R2012_B22 >NUL
call mkmk -a -g -w
call mkrtv
pause
