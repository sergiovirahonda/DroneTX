#include "joystick_driver.h"
#include <Arduino.h>

JoystickDriver::JoystickDriver(
    int pitchPin,
    int rollPin,
    int yawPin,
    int throttlePin
) {
    this->pitchPin = pitchPin;
    this->rollPin = rollPin;
    this->yawPin = yawPin;
    this->throttlePin = throttlePin;
}

int JoystickDriver::readPitch() {
    return analogRead(this->pitchPin);
}

int JoystickDriver::readRoll() {
    return analogRead(this->rollPin);
}

int JoystickDriver::readYaw() {
    return analogRead(this->yawPin);
}

int JoystickDriver::readThrottle() {
    return analogRead(this->throttlePin);
}