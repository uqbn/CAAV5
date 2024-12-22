@echo off
cd /d %~dp0..
set CNEXTOUTPUT=console
for %%i in ("%cd%") do set "CATDefaultEnvironment=Workspace_%%~ni"
"C:/Program Files/Dassault Systemes/B22/win_b64/code/bin/CATStart.exe" -nowindow -run CNEXT.exe
