#include "BlinkSignal.h"

#include "Arduino.h"

BlinkSignal::BlinkSignal(char pin, unsigned long pulseWidth) {
	this->pin = pin;
	this->lowPulseWidth = pulseWidth;
	this->highPulseWidth = pulseWidth;
	pinMode(pin, OUTPUT);
}

void BlinkSignal::update(unsigned long millis) {
	if (millis >= nextMillis) {
		if (countDown > 0) {
			countDown--;
			nextMillis = millis + highPulseWidth;
		} else {
			countDown = highPulseCount;
			nextMillis = millis + lowPulseWidth;
		}
		currentState = currentState == HIGH ? LOW : HIGH;
		illuminate();
	}
}

void BlinkSignal::illuminate() {
	// invert, since LED cathode is connected to GPIO pin
	digitalWrite(pin, currentState);
}
