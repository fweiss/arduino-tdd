#include "Arduino.h"
#include "BlinkSignal.h"

#define PIN 5
#define DELAY 500

BlinkSignal blinkSignal;

void setup() {
	pinMode(PIN, OUTPUT);
}

// The loop function is called in an endless loop
void loop() {
	blinkSignal.update(millis());
}
