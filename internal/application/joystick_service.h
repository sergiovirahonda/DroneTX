#ifndef JOYSTICK_SERVICE_H
#define JOYSTICK_SERVICE_H

#include "../infrastructure/joystick_driver.h"
#include "../domain/joystick_input.h"

class JoystickService {
    private:
        JoystickDriver& joystickDriver;

    public:
        JoystickService(JoystickDriver& joystickDriver);
        JoystickTrim calibrate();
        JoystickInput readJoystickInput(JoystickTrim trim);
        float manageCollector(JoystickTrim trim, float throttle, int increment);
};

#endif