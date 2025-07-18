#include "radio_service.h"

RadioService::RadioService(RadioDriver& radioDriver) : radioDriver(radioDriver) {}

void RadioService::executeDroneCommand(DroneCommand& packet) {
  radioDriver.send(packet);
}