
@echo off

pushd

if not exist build.win32 mkdir build.win32
cd build.win32

cmake -G"Visual Studio 12" ../

popd

pause
