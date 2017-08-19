#pragma once

#include "Arduino.h"

class BlinkSignal {
private:
    uint8_t pin = 1;
    bool invert = false;
    unsigned long lowPulseWidth = 1;
    unsigned long highPulseCount = 1;
    unsigned char currentState = 0;
    unsigned long nextMillis = 0;

    char countDown = 1;
    unsigned long highPulseWidth;
    void illuminate();
public:
    BlinkSignal(uint8_t pin, unsigned long offPulseWidth);
    void update(unsigned long millis);
    void invertOutput(bool invert);
    void setOffPulseWidth(unsigned long pulseWidth);
    void setOnPulseCount(uint8_t count);
};
