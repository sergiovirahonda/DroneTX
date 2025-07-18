#include "joystick_service.h"
#include <Arduino.h>

JoystickService::JoystickService(JoystickDriver& driver) : joystickDriver(driver) {}

JoystickTrim JoystickService::calibrate() {
    JoystickTrim trim(0, 0, 0, 0);
    int rawPitch = joystickDriver.readPitch();
    int rawRoll = joystickDriver.readRoll();
    int rawYaw = joystickDriver.readYaw();
    int rawThrottle = joystickDriver.readThrottle();

    int pitchMapped = map(rawPitch, 0, 1023, -100, 100);
    int rollMapped = map(rawRoll, 0, 1023, -100, 100);
    int yawMapped = map(rawYaw, 0, 1023, -100, 100);
    int throttleMapped = map(rawThrottle, 0, 1023, -100, 100);

    trim.setPitch(pitchMapped);
    trim.setRoll(rollMapped);
    trim.setYaw(yawMapped);
    trim.setThrottle(throttleMapped);

    return trim;
}

JoystickInput JoystickService::readJoystickInput(JoystickTrim trim) {
    JoystickInput input(0, 0, 0, 0);
    int rawPitch = joystickDriver.readPitch();
    int rawRoll = joystickDriver.readRoll();
    int rawYaw = joystickDriver.readYaw();
    int rawThrottle = joystickDriver.readThrottle();

    int pitchMapped = map(rawPitch, 0, 1023, -100, 100) - trim.getPitch();
    pitchMapped = pitchMapped * -1;

    int rollMapped = map(rawRoll, 0, 1023, -100, 100) - trim.getRoll();

    int yawMapped = map(rawYaw, 0, 1023, -100, 100) -  trim.getYaw();
    yawMapped = yawMapped * -1;

    int throttleMapped = map(rawThrottle, 0, 1023, -100, 100) - trim.getThrottle();

    input.setPitch(pitchMapped);
    input.setRoll(rollMapped);
    input.setYaw(yawMapped);
    input.setThrottle(throttleMapped);

    return input;
}

float JoystickService::manageCollector(JoystickTrim trim, float throttle, int increment) {
    if (abs(increment) < trim.getThrottleDeadZone()) {
        return throttle;
    }
    throttle += (increment * trim.getThrottleDeltaFactor());
    if (throttle > 100) {
        throttle = 100;
    }
    if (throttle < 0) {
        throttle = 0;
    }
    return throttle;
}





