#!/bin/bash

# Build script for DroneTX unit tests

set -e

echo "Building DroneTX unit tests..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the tests
make -j$(nproc)

echo "Build completed successfully!"
echo ""
echo "To run the tests, execute:"
echo "  ./build/drone_tx_tests"
echo ""
echo "Or run with CMake:"
echo "  cd build && ctest --verbose" 