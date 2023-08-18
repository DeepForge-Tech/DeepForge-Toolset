@echo off
mkdir tests
echo -- Building tests
g++ .\src\tests\MainTest.cpp -o .\tests\MainTest -lsqlite3 -ljsoncpp -lcurl -lgtest -lgmock -pthread -std=c++20
if ERRORLEVEL 0 (
   echo -- Build of tests was successfully.
   echo -- Running ".\tests\MainTest.exe"
   cd tests
   .\MainTest.exe
   cd ..
   cd ..
) else (
    echo -- Error in tests build.
)