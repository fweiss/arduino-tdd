#include "Arduino.h"

#define PIN 5
#define DELAY 500

void setup() {
	pinMode(PIN, OUTPUT);
}

// The loop function is called in an endless loop
void loop() {
	digitalWrite(PIN, HIGH);
	delay(DELAY);
	digitalWrite(PIN, LOW);
	delay(DELAY);
}
