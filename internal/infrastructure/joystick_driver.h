#ifndef JOYSTICK_DRIVER_H
#define JOYSTICK_DRIVER_H

#include <Arduino.h>

class JoystickDriver {
    private:
        int pitchPin;
        int rollPin;
        int yawPin;
        int throttlePin;

    public:
        JoystickDriver(
            int pitchPin,
            int rollPin,
            int yawPin,
            int throttlePin
        );
        int readPitch();
        int readRoll();
        int readYaw();
        int readThrottle(); 
};

#endif