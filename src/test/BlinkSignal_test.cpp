#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"

#include "BlinkSignal.h"

TEST(BlinkSignal, Basic) {
	ArduinoMock* arduinoMock = arduinoMockInstance();
	EXPECT_CALL(*arduinoMock, digitalWrite(1, 1));

	BlinkSignal bs;
	bs.update(0);
	releaseArduinoMock();
}
