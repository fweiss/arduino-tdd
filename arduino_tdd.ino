#include "Arduino.h"
#include "BlinkSignal.h"

#define PIN 5
#define DELAY 500

BlinkSignal blinkSignal(PIN, 200);

void setup() {
}

void loop() {
	blinkSignal.update(millis());
}
