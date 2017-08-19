#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"

#include "BlinkSignal.h"

using ::testing::InSequence;

TEST(BlinkSignal, Basic) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));

	BlinkSignal bs(1, 1);
	bs.update(0);
	releaseArduinoMock();
}

TEST(Basic, PinMode) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	EXPECT_CALL(*arduinoMock, pinMode(8, OUTPUT));

	BlinkSignal bs(8, 1);
	releaseArduinoMock();
}

TEST(Basic, Invert) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	EXPECT_CALL(*arduinoMock, digitalWrite(1, LOW));

	BlinkSignal bs(1, 1);
	bs.invertOutput(true);
	bs.update(0);
	releaseArduinoMock();

}

TEST(Basic, PinNumberWrite) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	EXPECT_CALL(*arduinoMock, digitalWrite(3, HIGH));

	BlinkSignal bs(3, 1);
	bs.update(0);
	releaseArduinoMock();
}

TEST(BlinkSignal, Square) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	{
		InSequence s1;
		EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, LOW));
	}

	BlinkSignal blinkSignal(1, 1);
	blinkSignal.update(0);
	blinkSignal.update(1);
	releaseArduinoMock();
}

TEST(Square, Pulewidth) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));
	EXPECT_CALL(*arduinoMock, digitalWrite(1, LOW));

	BlinkSignal blinkSignal(1, 2);
	blinkSignal.setOffPulseWidth(2);
	blinkSignal.update(0);
	blinkSignal.update(1);
	blinkSignal.update(2);
	releaseArduinoMock();
}

TEST(Square, Frequency) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	{
		InSequence s1;
		EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, LOW));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));
	}
	BlinkSignal blinkSignal(1, 503);
	blinkSignal.setOffPulseWidth(503);
	blinkSignal.update(0);
	blinkSignal.update(503);
	blinkSignal.update(1006);
	releaseArduinoMock();
}

TEST(PulseTrain, Two) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	{
		InSequence s1;
		EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, LOW));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, LOW));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, LOW));
	}
	BlinkSignal blinkSignal(1, 60);
	blinkSignal.setOffPulseWidth(60);
	blinkSignal.setOnPulseCount(2);

	blinkSignal.update(0);
	blinkSignal.update(20);
	blinkSignal.update(40);
	blinkSignal.update(60);
	blinkSignal.update(120);
	blinkSignal.update(140);

	releaseArduinoMock();
}

TEST(PulseTrain, TwoWide) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	{
		InSequence s1;
		EXPECT_CALL(*arduinoMock, digitalWrite(1, HIGH));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, LOW));
	}
	BlinkSignal blinkSignal(1, 500);
	blinkSignal.setOffPulseWidth(500);
	blinkSignal.setOnPulseCount(2);

	blinkSignal.update(0);
	blinkSignal.update(166);

	releaseArduinoMock();
}

