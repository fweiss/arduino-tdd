#include "BlinkSignal.h"

#ifndef UNIT_TESTING
#include "Arduino.h"
#else
#include "arduino-mock/Arduino.h"
#endif

void BlinkSignal::update(unsigned long millis) {
	digitalWrite(1, 1);
}
