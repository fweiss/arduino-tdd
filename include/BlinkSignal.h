#pragma once

class BlinkSignal {
private:
	unsigned char pin = 1;
	unsigned long pulseWidth = 1;
	unsigned char currentState = 0;
	unsigned long nextMillis = 0;
public:
	BlinkSignal(char pin, unsigned long pulsWidth);
	void update(unsigned long millis);
	void setPulseWidth(unsigned long pulseWidth) {
		this->pulseWidth = pulseWidth;
	}
};
