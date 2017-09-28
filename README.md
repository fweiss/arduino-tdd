# arduino-tdd
A starter project to demo a toolchain for developing Arduino applications using TDD

## What is TDD
Test Driven Development (TDD) is a coding practice whereby automated tests are executed before working code is written.
A defining mantra of TDD is **RED, GREEN, REFACTOR**.
There are many benefits of this approach, although some software engineers feel that it gets in the way.
Once you master the basics, which are faciliated by many frameworks such as JUnit and RSpec, you'll find that the
resulting code **sum tests** are way better to maintain and extend.

## Motivation
I have developed several Arduino projects without TDD. I have always felt that before trying to manually verify the outputs
of the actuators manually, the code should have be tested. And furthermore, I believe code that's written test-first is better code.
I have finally sat down to accomplish this. I hope this inspires other embedded enginers to practice TDD.

## Target toolchain
After looking into many options, this toolchain was chosen:
- Eclipse Oxygen 4.7
- The Arduino Eclipse Plugin named Sloeber V4
- Google Test
- Arduino Mock

There is an Eclipse Arduino tool which was tried. It was deemed not as good as the Sloeber tool.

The following operating systems were used to validate this project:
- Windows 7
- Mac OS

The following guide is indispensible - do follow it, as it is complete and detailed: http://mitchtronic.blogspot.com/2017/03/setting-up-google-test-google-mock.html

## Setup the toolchain

Setting up the toolchain is a bit elaborate, especially since there'a no plugin yet for Google Test.

### Setup Milestones

1. Eclipse up and running
1. Deploy a simple sketch to the device with Sloeber
1. Running a simple gtest
1. Develop a simple Aruino project with TDD
1. Deploy the simple project to the device

### Eclipse
Installation of Eclipse and the requisite JDK is straight-forward.
The Sloeber plugin can be found in the Eclipse Marketplace.

Note: there are two Sloeber plugin. The one with the most downloads was chosen.

Important: You also need the CDT plugin, even if you have installed the CDT bundled version of Eclipse.

### Building ardiuno-mock
It's OK to create a build sub directory and do the cmake/nake build there.

At step 7 add the include directory "include/arduino-mock", in addition to the directory "include".
This eliminates the need for the UNIT_TESTING define in the tests and its usage in the non-test code.
The non-test case includes "Arduino.h" as usual, but in the gtest configuration it is searched for in
the directory include/arduino-mock instead of the directory "core".

At step 8 it says to switch configurations with the hammer toolbar button.
That didn't work. However, using the launcher Run button for tests and the Arduino Upload Sketch button sufficed.

Be sure to run the gtest build at the end of step 9 before starting on Step 10.

In gtest configuration, set language version to C++11. This permits using more modern C++.

### Setting up run configurations
For the Release environment, add the include directory, but that directory ought to be split between test and release.

## Target platforms
The following IoT platforms were used to validate this project:
- Sparkfun ESP8266 Thing Dev (a spare device I had which also had built-in FTDI)

## Platform support
Sloeber comes equipped with several platforms.

To add an addtional platform/board:
- Preferences > Arduino > Third party index url's
- Add the url
- Preferences > Arduino > Platforms and Boards
- Navigate down to a specific board and version
- Select the platform/board(s)

Wait for the download to complete. Download status is shown in the lower right corner of the Eclipse window.

Adafruit provide a lengthy catalog of Arduino platform URLs: https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls#list-of-3rd-party-boards-support-urls

### Sparkfun ESP8266 Thing Dev

The URL is http://arduino.esp8266.com/stable/package_esp8266com_index.json

Select the eSP8266/esp8266/2.3.0 platform.

### Adafruit Bluefruit M0 and 32u2

The URL is https://adafruit.github.io/arduino-board-index/package_adafruit_index.json

The platform for M0 is Adafruit SAMD 1.0.19

The platform for 32u4 isAdafruit AVR Boards 1.4.9

## Debugging unit tests

One of the joys of unit testing is being able to step through the code under controlled circumstances. 
You will need to have a C++ debugger available for CDT and configure the compiler to provide debug information in the executable.

https://www.ics.uci.edu/~pattis/common/handouts/macmingweclipse/allexperimental/mac-gdb-install.html

The CDT debugger won't work well unless you tell the compiler to include debug information.
Open the project properties. Navigate to C/C++ Settings. Then select your test configuration (gtest).
Navigate to GCC C++ Compiler > Dubugging. For the Debugging level, select default (-g).

Eclipse Oxygen has experimental integration with LLDB, which may be handy if you are using an LLVM compiler, such as Mac OS X.

