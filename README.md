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

The following guide is indispensible - do follow as it is complete and detailed: http://mitchtronic.blogspot.com/2017/03/setting-up-google-test-google-mock.html

## Setup the toolchain

Setting up the toolchain is a bit elaborate, especially since there'a no plugin yet for Google Test.

### Eclipse
Installation of Eclipse and the requisite JDK are straight forward.
The Sloeber plugin can be found in the Eclipse Marketplace.

Note: there are two Sloever plugin. The one with the most downloads was chosen.

Important: You also need the CDT plugin, even if you have install the CDT bundled version of Eclipse.

### Setup Milestones

1. Eclipse up and running
2. Deploy a simple sketch to the device with Sloeber
3. Running a simple gtest
4. Develop a simple Aruino project with TDD
1. Deploy the simple project to the device

## Target platforms
The following IoT platforms were used to validate this project:
- Sparkfun ESP8266 Thing Dev

## Platform support
Sloeber come equipped with several platforms.

To add a platform/board:
- Preferences > Arduino > Third party index url's
- Add the url
- Preferences > Arduino > Platforms and Boards
- Navigate down to a specific board and version
- Select the platform/board

Wait for the download to complete. Download status is shown in the lower right corner of the Eclipse window.

### Sparkfun ESP8266 Thing Dev

The URL is URL http://arduino.esp8266.com/stable/package_esp8266com_index.json

Select the eSP8266/esp8266/2.3.0 platform.
