#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"

#include "BlinkSignal.h"

using ::testing::InSequence;

TEST(BlinkSignal, Basic) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	EXPECT_CALL(*arduinoMock, digitalWrite(1, 1));

	BlinkSignal bs;
	bs.update(0);
	releaseArduinoMock();
}

TEST(BlinkSignal, Square) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	{
		InSequence s1;
		EXPECT_CALL(*arduinoMock, digitalWrite(1, 1));
		EXPECT_CALL(*arduinoMock, digitalWrite(1, 0));
	}

	BlinkSignal blinkSignal;
	blinkSignal.update(0);
	blinkSignal.update(1);
	releaseArduinoMock();
}
