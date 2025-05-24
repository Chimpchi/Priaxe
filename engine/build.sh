#!/bin/bash
# Build script for engine

set -e # Exit on error
cFilenames=$(find . -name "*.c")

# Define variables
assembly="libengine"
compilerFlags="-g -shared -w"
includeFlags="-Isrc"
linkerFlags="-lvulkan -lxcb -lX11 -lX11-xcb"
defines="-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS"

echo "Building $assembly..."
gcc $cFilenames $compilerFlags -o ../bin/$assembly.so $defines $includeFlags $linkerFlags
sudo cp ../bin/$assembly.so /usr/lib