#!/bin/bash
# Build script for testbed

set -e # Exit on error
cFilenames=$(find . -name "*.c")

# Define variables
assembly="testbed"
outputPath="../$1"
compilerFlags="-g -w"
includeFlags="-Isrc -I../engine/src/"
linkerFlags="-L../bin -lengine"
defines="-D_DEBUG -DKIMPORT"

echo "Building $assembly..."
gcc $cFilenames $compilerFlags -o $outputPath$assembly $defines $includeFlags $linkerFlags