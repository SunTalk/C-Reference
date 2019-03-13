@echo off

for /L %%i in (1 1 100) do (
	run Simple
	pushd Simple
	block.exe
	popd
)

for /L %%i in (1 1 100) do (
	run Iterator
	pushd Iterator
	block.exe
	popd
)

for /L %%i in (1 1 100) do (
	run Alternative
	pushd Alternative
	block.exe
	popd
)
