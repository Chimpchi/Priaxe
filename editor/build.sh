#!/bin/bash
# Build script for editor

set -e # Exit on error
cFilenames=$(find . -name "*.c")

# Define variables
assembly="libeditor"
outputPath=../"$1"
compilerFlags="-g -w"
includeFlags="-Isrc -I../engine/src/"
linkerFlags="-L../bin -lengine"
defines="-D_DEBUG -DKEXPORT"

echo "Building $assembly..."
gcc $cFilenames $compilerFlags -o $outputPath$assembly.so $defines $includeFlags $linkerFlags