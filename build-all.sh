#!/bin/bash
# Build Everything

set -e #Exit on error
echo "Build everything..."
outputPath=bin/linux/
mkdir -p "$outputPath"

# Build engine
pushd engine >/dev/null
./build.sh $outputPath
popd >/dev/null

# Build testbed
pushd testbed >/dev/null
./build.sh $outputPath
popd >/dev/null

echo "All assemblies built successfully."