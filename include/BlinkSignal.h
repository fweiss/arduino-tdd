#pragma once

class BlinkSignal {
private:
	unsigned char pin = 1;
	bool invert = false;
	unsigned long lowPulseWidth = 1;
	char highPulseCount = 1;
	unsigned char currentState = 0;
	unsigned long nextMillis = 0;

	char countDown = 1;
	unsigned long highPulseWidth;
	void illuminate();
public:
	BlinkSignal(char pin, unsigned long offPulseWidth);
	void update(unsigned long millis);
	void invertOutput(bool invert);
	void setOffPulseWidth(unsigned long pulseWidth) {
		this->lowPulseWidth = pulseWidth;
	}
	void setOnPulseCount(char count) {
		this->highPulseCount = count * 2 - 1;
		this->highPulseWidth = lowPulseWidth / highPulseCount ;
		this->countDown = this->highPulseCount;
	}
};
