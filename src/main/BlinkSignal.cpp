#include "BlinkSignal.h"

#include "Arduino.h"

BlinkSignal::BlinkSignal(char pin, unsigned long pulseWidth) {
	this->pin = pin;
	this->lowPulseWidth = pulseWidth;
	this->highPulseWidth = pulseWidth;
	pinMode(pin, OUTPUT);
}

void BlinkSignal::invertOutput(bool invert) {
	this->invert = invert;
}

void BlinkSignal::setOffPulseWidth(unsigned long pulseWidth) {
	this->lowPulseWidth = pulseWidth;
}

void BlinkSignal::setOnPulseCount(char count) {
	this->highPulseCount = count * 2 - 1;
	this->highPulseWidth = lowPulseWidth / highPulseCount ;
	this->countDown = this->highPulseCount;
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
	uint8_t value = invert ? (currentState == HIGH ? LOW : HIGH): currentState;
	digitalWrite(pin, value);
}
