#include "Arduino.h"
#include "BlinkSignal.h"

#define PIN 5
#define DELAY 1500

BlinkSignal blinkSignal(PIN, DELAY);

void setup() {
	blinkSignal.invertOutput(true);
	blinkSignal.setOnPulseWidth(5);
}

void loop() {
	blinkSignal.update(millis());
}
