#include "Arduino.h"
#include "BlinkSignal.h"

#define PIN 13
#define DELAY 1500

BlinkSignal blinkSignal(PIN, DELAY);

void setup() {
//	blinkSignal.invertOutput(true);
	blinkSignal.setOnPulseCount(5);
}

void loop() {
	blinkSignal.update(millis());
}
