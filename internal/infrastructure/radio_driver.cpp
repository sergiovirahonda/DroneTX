#include "radio_driver.h"
#include <SPI.h>

RadioDriver::RadioDriver(int cePin, int csnPin, byte address) {
    this->cePin = cePin;
    this->csnPin = csnPin;
    this->address = address;
    this->radio = RF24(cePin, csnPin);
}

void RadioDriver::begin() {
    radio.begin();
    radio.setPALevel(RF24_PA_LOW);
    radio.openWritingPipe(this->address);
    radio.stopListening(); // TX mode
}

void RadioDriver::send(const DroneCommand& packet) {
    radio.write(&packet, sizeof(packet));
}