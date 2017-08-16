#include "BlinkSignal.h"

#ifndef UNIT_TESTING
#include "Arduino.h"
#else
#include "arduino-mock/Arduino.h"
#endif

void BlinkSignal::update(unsigned long millis) {
	uint8_t value = millis == 0 ? HIGH : LOW;
	digitalWrite(1, value);
}
