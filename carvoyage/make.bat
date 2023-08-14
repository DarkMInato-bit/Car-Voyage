@echo off

set SRC_DIR=src
set HEADER_DIR=header
set OUT_DIR=out

:: Create the output directory if it doesn't exist
mkdir %OUT_DIR% 2>nul

:: Compile and link
g++ -o %OUT_DIR%\my_program %SRC_DIR%\carvoyage.cpp %SRC_DIR%\customer.cpp %SRC_DIR%\menu.cpp %SRC_DIR%\login.cpp %SRC_DIR%\renter.cpp -I %HEADER_DIR%

:: Run the program
cd %OUT_DIR%
./my_project

echo Compilation and execution completed.

