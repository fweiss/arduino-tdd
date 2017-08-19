#include "Arduino.h"
#include "BlinkSignal.h"

#define PIN 13
#define DELAY 1000

BlinkSignal blinkSignal(PIN, DELAY);

void setup() {
	blinkSignal.setOnPulseWidth(3);
}

void loop() {
	blinkSignal.update(millis());
}
