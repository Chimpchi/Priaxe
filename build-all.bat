@ECHO OFF
REM Build Everything

ECHO "Building everything..."
SET outputPath=./bin/windows/
mkdir "%outputPath%"

PUSHD engine
CALL build.bat %outputPath%
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

PUSHD testbed
CALL build.bat %outputPath%
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

ECHO "All assemblies built successfully."