// External Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Arduino.h>

// Internal Libraries
#include "internal/domain/drone_command.h"
#include "internal/domain/joystick_input.h"
#include "internal/infrastructure/joystick_driver.h"
#include "internal/infrastructure/radio_driver.h"
#include "internal/application/joystick_service.h"
#include "internal/application/radio_service.h"

// Define radio CE & CSN pins
#define CE_PIN  9
#define CSN_PIN 10
const byte address[6] = "00001";

// Define Joystick pins

#define YAW_PIN A0       // Left stick X-axis
#define THROTTLE_PIN A1  // Left stick Y-axis
#define ROLL_PIN A2      // Right stick X-axis
#define PITCH_PIN A3     // Right stick Y-axis

// Define global variables
float collector = 0.0;

// Define drivers
JoystickDriver joystickDriver(PITCH_PIN, ROLL_PIN, YAW_PIN, THROTTLE_PIN);
RadioDriver radioDriver(CE_PIN, CSN_PIN, address);

// Define services
JoystickService joystickService(joystickDriver);
RadioService radioService(radioDriver);

DroneCommand droneCommand(0, 0, 0, 0, 0);
JoystickTrim trim(0, 0, 0, 0);

void setup() {
    Serial.begin(9600);
    radioDriver.begin();
    trim = joystickService.calibrate();
}

void loop() {
    JoystickInput joystickInput = joystickService.readJoystickInput(trim);
    droneCommand.setPitch(joystickInput.getPitch());
    droneCommand.setRoll(joystickInput.getRoll());
    droneCommand.setYaw(joystickInput.getYaw());
    collector = joystickService.manageCollector(
        trim,
        collector,
        joystickInput.getThrottle()
    );
    droneCommand.setThrottle(collector);
    droneCommand.setTimestamp(millis());
    radioService.executeDroneCommand(droneCommand);
    delay(50);
}