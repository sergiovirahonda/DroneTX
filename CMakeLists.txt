cmake_minimum_required(VERSION 3.16)
project(DroneTX_Tests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GoogleTest
find_package(GTest REQUIRED)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/internal
)

# Source files for the domain layer only
set(APP_SOURCES
    internal/domain/drone_command.cpp
    internal/domain/joystick_input.cpp
)

# Test source files (domain only)
set(TEST_SOURCES
    tests/domain/drone_command_test.cpp
    tests/domain/joystick_input_test.cpp
    tests/main.cpp
)

# Create test executable
add_executable(drone_tx_tests
    ${APP_SOURCES}
    ${TEST_SOURCES}
)

# Link GoogleTest
target_link_libraries(drone_tx_tests GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()
add_test(NAME DroneTX_Tests COMMAND drone_tx_tests)

# Set compiler flags for tests
target_compile_definitions(drone_tx_tests PRIVATE
    UNIT_TESTING=1
    ARDUINO=0
) 