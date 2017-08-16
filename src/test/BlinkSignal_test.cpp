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
	blinkSignal.setPulseWidth(2);
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
	blinkSignal.setPulseWidth(503);
	blinkSignal.update(0);
	blinkSignal.update(503);
	blinkSignal.update(1006);
	releaseArduinoMock();
}