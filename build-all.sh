#!/bin/bash
# Build Everything

set -e #Exit on error
echo "Build everything..."

# Build engine
pushd engine >/dev/null
./build.sh
popd >/dev/null

# Build testbed
pushd testbed >/dev/null
./build.sh
popd >/dev/null

echo "All assemblies built successfully."