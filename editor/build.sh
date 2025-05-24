#!/bin/bash
# Build script for editor

set -e # Exit on error
cFilenames=$(find . -name "*.c")

# Define variables
assembly="libeditor"
compilerFlags="-g -w"
includeFlags="-Isrc -I../engine/src/"
linkerFlags="-L../bin -lengine"
defines="-D_DEBUG -DKEXPORT"

echo "Building $assembly..."
gcc $cFilenames $compilerFlags -o ../bin/$assembly.so $defines $includeFlags $linkerFlags