# arduino-tdd
A starter project to demo a toolchain for developing Arduino applications using TDD

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

At step 8 it says to switch configurations with the hammer toolbar button.
That didn't work. However, using the launcher Run button for tests and the Arduino Upload Sketch button sufficed.

Be sure to run the gtest build at the end of step 9 before starting on Step 10.

Tip: Instead of #define UNIT_TESTING in each test file, you can add it the the gtest run configuration.
Navigate to GCC C++ Compiler > Preprocessor.

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

### Sparkfun ESP8266 Thing Dev

The URL is http://arduino.esp8266.com/stable/package_esp8266com_index.json

Select the eSP8266/esp8266/2.3.0 platform.
