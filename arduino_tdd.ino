#include "Arduino.h"
#include "BlinkSignal.h"

#define PIN 5
#define DELAY 500

BlinkSignal blinkSignal(PIN, DELAY);

void setup() {
	blinkSignal.setHighPulseCount(2);
}

void loop() {
	blinkSignal.update(millis());
}
