@echo off

cls
echo start generate
g++ generate.cpp -o generate.exe
generate %1

echo end generate
echo start HW03
g++ HW03.cpp -o HW03.exe -DDBG
HW03.exe

echo Finish
