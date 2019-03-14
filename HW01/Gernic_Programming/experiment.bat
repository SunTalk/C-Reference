@echo off

for /L %%i in (1 1 100) do (

	echo Simple %%i
	run Simple
	pushd Simple
	block.exe
	popd

	echo Iterator %%i
	run Iterator
	pushd Iterator
	block.exe
	popd

	echo Alternative %%i
	run Alternative
	pushd Alternative
	block.exe
	popd


)
