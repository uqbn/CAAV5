@echo off
cd /d %~dp0..
call "C:/Program Files/Dassault Systemes/B22/win_b64/code/bin/CATStart.exe" -nowindow -run "%~dp0../win_b64/code/bin/CAAPluginRun.exe"
pause