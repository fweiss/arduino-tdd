#include "BlinkSignal.h"

BlinkSignal::BlinkSignal(uint8_t pin, unsigned long pulseWidth) {
    this->pin = pin;
    this->offPulseWidth = pulseWidth;
    this->onPulseWidth = pulseWidth;
    pinMode(pin, OUTPUT);
}

void BlinkSignal::invertOutput(bool invert) {
    this->invert = invert;
}

void BlinkSignal::setOffPulseWidth(unsigned long pulseWidth) {
    this->offPulseWidth = pulseWidth;
}

void BlinkSignal::setOnPulseCount(uint8_t count) {
    this->highPulseCount = count * 2 - 1;
    this->onPulseWidth = offPulseWidth / highPulseCount ;
    this->countDown = this->highPulseCount;
}


void BlinkSignal::update(unsigned long millis) {
    if (millis >= nextMillis) {
        if (countDown > 0) {
            countDown--;
            nextMillis = millis + onPulseWidth;
        } else {
            countDown = highPulseCount;
            nextMillis = millis + offPulseWidth;
        }
        currentState = currentState == HIGH ? LOW : HIGH;
        illuminate();
    }
}

void BlinkSignal::illuminate() {
    // invert, since LED cathode is connected to GPIO pin
    uint8_t value = invert ? (currentState == HIGH ? LOW : HIGH): currentState;
    digitalWrite(pin, value);
}
