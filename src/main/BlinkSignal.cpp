#include "BlinkSignal.h"

#ifndef UNIT_TESTING
#include "Arduino.h"
#else
#include "arduino-mock/Arduino.h"
#endif

BlinkSignal::BlinkSignal(char pin, unsigned long pulseWidth) {
	this->pin = pin;
	this->pulseWidth = pulseWidth;
	pinMode(pin, OUTPUT);
}

void BlinkSignal::update(unsigned long millis) {
	if (millis >= nextMillis) {
		nextMillis = millis + pulseWidth;
		currentState = currentState == HIGH ? LOW : HIGH;
		digitalWrite(pin, currentState);
	}
}
