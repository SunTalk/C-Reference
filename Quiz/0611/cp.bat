@echo off

cls
echo COMPILING...

g++ %1.cpp -o %1.exe -DDBG

if %ERRORLEVEL% EQU 0 (
	echo FINISH
	%1.exe
	)