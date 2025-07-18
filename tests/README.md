# DroneTX Unit Tests

This directory contains unit tests for the DroneTX Arduino drone transmitter project using GoogleTest.

## Overview

The testing framework provides:
- **Unit tests** for the domain layer (business logic and data structures)
- **CMake build system** for easy compilation and execution
- **Simple setup** that doesn't require modifying production code

## Directory Structure

```
tests/
├── domain/                   # Domain layer tests
│   ├── drone_command_test.cpp
│   └── joystick_input_test.cpp
├── main.cpp                  # Test runner
└── README.md                 # This file
```

## Prerequisites

- **CMake** (version 3.16 or higher)
- **GoogleTest** library
- **C++17** compatible compiler (GCC, Clang, or MSVC)

### Installing Dependencies

#### macOS (using Homebrew)
```bash
brew install cmake googletest
```

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install cmake libgtest-dev libgmock-dev
```

#### Windows (using vcpkg)
```bash
vcpkg install gtest
```

## Building and Running Tests

### Quick Start
```bash
# Build and run tests
./build_tests.sh

# Or manually:
mkdir build && cd build
cmake ..
make
./drone_tx_tests
```

### Running Specific Tests
```bash
# Run all tests
./drone_tx_tests

# Run tests with verbose output
./drone_tx_tests --gtest_verbose

# Run specific test suite
./drone_tx_tests --gtest_filter=DroneCommandTest*

# Run specific test
./drone_tx_tests --gtest_filter=DroneCommandTest.Constructor_ValidValues_SetsAllProperties
```

### Using CMake Test Integration
```bash
cd build
ctest --verbose
```

## Test Categories

### Domain Layer Tests
- **DroneCommand**: Tests for drone command data structure
- **JoystickInput**: Tests for joystick input data structure
- **JoystickTrim**: Tests for joystick trim calibration

## Test Naming Convention

Tests follow the pattern: `ClassName.MethodName_Scenario_ExpectedResult`

Examples:
- `DroneCommandTest.Constructor_ValidValues_SetsAllProperties`
- `JoystickInputTest.SetPitch_ValidValue_UpdatesPitch`
- `JoystickTrimTest.Reset_ResetsAllValuesToZero`

## Adding New Tests

### 1. Create Test File
Create a new test file in the appropriate directory:
```cpp
#include <gtest/gtest.h>
#include "your_class.h"

class YourClassTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
};

TEST_F(YourClassTest, MethodName_Scenario_ExpectedResult) {
    // Arrange
    // Act
    // Assert
}
```

### 2. Update CMakeLists.txt
Add your test file to the `TEST_SOURCES` list in `CMakeLists.txt`.

### 3. Build and Run
```bash
./build_tests.sh
```

## Continuous Integration

The test suite is designed to be easily integrated into CI/CD pipelines:

```yaml
# Example GitHub Actions workflow
- name: Build and Test
  run: |
    ./build_tests.sh
    cd build && ctest --output-on-failure
```

## Troubleshooting

### Common Issues

1. **CMake not found**: Install CMake using your package manager
2. **GoogleTest not found**: Install GoogleTest development libraries
3. **Compilation errors**: Ensure you're using a C++17 compatible compiler

### Debug Mode
```bash
# Build with debug information
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

## Contributing

When adding new features to the DroneTX project:

1. **Write tests first** (TDD approach) for any new domain classes
2. **Use descriptive test names** following the convention
3. **Ensure good test coverage** for new functionality
4. **Update this README** if adding new test categories

## Philosophy

This testing setup follows a pragmatic approach:
- **Test what's easily testable** without modifying production code
- **Focus on domain logic** which is the most critical business logic
- **Keep it simple** - no complex mocking or infrastructure dependencies
- **Don't force testing** on code that would require significant refactoring

## License

This testing framework is part of the DroneTX project and follows the same license terms. 