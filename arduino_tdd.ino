#include "Arduino.h"
#include "BlinkSignal.h"

#define PIN 5
#define DELAY 500

BlinkSignal blinkSignal(PIN, DELAY);

void setup() {
}

void loop() {
	blinkSignal.update(millis());
}
