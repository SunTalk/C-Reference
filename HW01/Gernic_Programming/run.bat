@echo off

cls

pushd %1 

g++ -std=c++11 -I.. gen_string.cpp -o gen_string.exe

g++ -std=c++11 -I.. main.cpp -o main.exe

if %ERRORLEVEL% EQU 0 (

	::set lines = (100 200 300)
	::set len   = 100 200 300
	for %%a in (100 200 300) do (

		for %%b in (100 200 300) do (

			gen_string.exe %%a %%b
			main.exe  "randString_%%a_%%b.txt"
		)
	) 
	echo "gen_string finished"
)

popd
