#include "../domain/drone_command.h"
#include "../infrastructure/radio_driver.h"

#ifndef RADIO_SERVICE_H
#define RADIO_SERVICE_H

class RadioService {
    private:
        RadioDriver& radioDriver;
    public:
        RadioService(RadioDriver& radioDriver);
        void executeDroneCommand(DroneCommand& drone_command);
};

#endif