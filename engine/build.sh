#!/bin/bash
# Build script for engine

set -e # Exit on error
cFilenames=$(find . -name "*.c")

# Define variables
assembly="libengine"
outputPath="./$1"
compilerFlags="-g -shared -w"
includeFlags="-Isrc"
linkerFlags="-lvulkan -lxcb -lX11 -lX11-xcb"
defines="-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS"

echo "Building $assembly..."
gcc $cFilenames $compilerFlags -o $outputPath$assembly.so $defines $includeFlags $linkerFlags
sudo cp $outputPath$assembly.so /usr/lib