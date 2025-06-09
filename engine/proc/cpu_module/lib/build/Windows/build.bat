@echo off
setlocal enabledelayedexpansion

:: === CONFIGURATION ===
set "BUILD_DIR=..\..\build\Windows"
set "LIB_DIR=..\..\libs\Windows"
set "SRC_DIR=..\..\..\src"
set "INC_DIR=..\..\..\inc"
set "MODULE_NAME=%~1"
set "MODE=%~2"

:: === ARGUMENT VALIDATION ===
if "%MODULE_NAME%"=="" (
    echo Usage: %~nx0 MODULE_NAME [MODE: stable^|test]
    exit /b 1
)
if "%MODE%"=="" (
    set "MODE=test"
)

echo Building module: %MODULE_NAME% [Mode: %MODE%]
echo Current directory: %cd%

:: === Ensure output dirs exist ===
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
)
if not exist "%LIB_DIR%\%MODE%" (
    mkdir "%LIB_DIR%\%MODE%"
)

:: === FIND .inc FILE ===
set "INC_FILE=%INC_DIR%\%MODULE_NAME%.inc"
set "inc="

if exist "%INC_FILE%" (
    echo Found include file: %INC_FILE%
    for /F "usebackq tokens=* delims=" %%a in ("%INC_FILE%") do (
        echo Adding dependency: %%a
        set "inc=!inc! ..\..\..\%%a_module\lib\build\Windows\l%%a.o"
    )
) else (
    echo No .inc file found at: %INC_FILE%
)

:: === COMPILE ===
set "SRC_FILE=%SRC_DIR%\%MODULE_NAME%.c"
if not exist "%SRC_FILE%" (
    echo ERROR: Source file not found: %SRC_FILE%
    exit /b 1
)

echo Compiling: %SRC_FILE%
gcc -c -o "%BUILD_DIR%\l%MODULE_NAME%.o" "%SRC_FILE%" -DCALCDLL_EXPORTS -I..\..\..\includes -I..\..\..\error_module

:: === LINK ===
echo Linking: %LIB_DIR%\%MODE%\l%MODULE_NAME%.dll
gcc -o "%LIB_DIR%\%MODE%\l%MODULE_NAME%.dll" "%BUILD_DIR%\l%MODULE_NAME%.o" !inc! -s -shared

echo Build finished successfully.
endlocal
