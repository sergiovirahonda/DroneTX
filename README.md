# DroneTX - Arduino Drone Transmitter

A simple drone controller transmitter built with Arduino, featuring a clean architecture with focused unit testing.

## Overview

DroneTX is an Arduino-based drone transmitter that provides:
- **Joystick input processing** with calibration and trim support
- **Radio communication** using nRF24L01 modules
- **Clean architecture** with separated domain, application, and infrastructure layers
- **Focused unit testing** for domain logic using GoogleTest

## Architecture

The project follows a clean architecture pattern with three main layers:

```
internal/
├── domain/           # Business logic and data structures
│   ├── drone_command.h/cpp
│   └── joystick_input.h/cpp
├── application/      # Application services
│   ├── joystick_service.h/cpp
│   └── radio_service.h/cpp
└── infrastructure/   # Hardware interfaces
    ├── joystick_driver.h/cpp
    └── radio_driver.h/cpp
```

## Hardware Requirements

- **Arduino board** (Uno, Nano, or compatible)
- **nRF24L01 radio module**
- **4-axis joystick** or individual potentiometers
- **Connecting wires**

## Pin Configuration

```cpp
// Radio pins
#define CE_PIN  9
#define CSN_PIN 10

// Joystick pins
#define YAW_PIN A0       // Left stick X-axis
#define THROTTLE_PIN A1  // Left stick Y-axis
#define ROLL_PIN A2      // Right stick X-axis
#define PITCH_PIN A3     // Right stick Y-axis
```

## Installation

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd DroneTX
   ```

2. **Install Arduino IDE** and required libraries:
   - SPI (built-in)
   - nRF24L01
   - RF24

3. **Upload the sketch**
   - Open `DroneTX.ino` in Arduino IDE
   - Select your board and port
   - Upload the sketch

## Usage

1. **Power on** the transmitter
2. **Calibration** occurs automatically on startup
3. **Control the drone** using the joysticks:
   - Left stick: Yaw (left/right) and Throttle (up/down)
   - Right stick: Roll (left/right) and Pitch (up/down)

## Testing

The project includes a focused unit testing framework using GoogleTest for domain logic.

### Quick Start
```bash
# Build and run all tests
./build_tests.sh

# Or manually
mkdir build && cd build
cmake ..
make
./drone_tx_tests
```

### Test Coverage
- **Domain Layer**: Data structures and business logic (25 tests)
- **Focus**: Core business logic that doesn't require hardware dependencies

For detailed testing information, see [tests/README.md](tests/README.md).

## Development

### Prerequisites
- **Arduino IDE** or **PlatformIO**
- **CMake** (for testing)
- **GoogleTest** (for testing)

### Building Tests
```bash
# Install dependencies (macOS)
brew install cmake googletest

# Build tests
./build_tests.sh
```

### Adding Features
1. **Write tests first** (TDD approach) for domain logic
2. **Follow the architecture** layers
3. **Keep production code unchanged** for testing
4. **Update documentation** as needed

## Testing Philosophy

This project follows a pragmatic testing approach:
- **Test what's easily testable** without modifying production code
- **Focus on domain logic** which is the most critical business logic
- **Keep it simple** - no complex mocking or infrastructure dependencies
- **Don't force testing** on code that would require significant refactoring

## Contributing

1. Fork the repository
2. Create a feature branch
3. Write tests for new domain functionality
4. Implement the feature
5. Ensure all tests pass
6. Submit a pull request

## License

[Add your license information here]

## Troubleshooting

### Common Issues
- **Radio not connecting**: Check wiring and address configuration
- **Joystick not responding**: Verify pin connections and analog readings
- **Test build failures**: Ensure GoogleTest is properly installed

### Debug Mode
```bash
# Build with debug information
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```
