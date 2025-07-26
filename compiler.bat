@echo off
setlocal

cls

if "%~1"=="" (
    echo Usage: compiler.bat ^<folder^>
    exit /b 1
)

set "SRC_DIR=%~1"
set "SRC_FILE=%SRC_DIR%\main.c"
set "BIN_DIR=bin"
set "TARGET=%BIN_DIR%\%SRC_DIR%.exe"

if not exist "%SRC_FILE%" (
    echo Error: "%SRC_FILE%" not found.
    exit /b 1
)

if not exist "%BIN_DIR%" (
    mkdir "%BIN_DIR%"
)

gcc "%SRC_FILE%" -o "%TARGET%"

if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b
)

"%TARGET%"

endlocal
