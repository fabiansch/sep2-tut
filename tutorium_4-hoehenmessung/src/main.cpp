/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.2
 * @desc    Demoprojekt für die Höhenmessung.
 */

#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <unistd.h>
#include "lib/HWaccess.h"

using namespace std;

void setLights(int heightvalue) {
  static const uint16_t registerAddress  = 0x300;
  static const uint8_t redLightBitmask = 0b10000000;
  static const uint8_t yellowLightBitmask = 0b01000000;
  static const uint8_t greenLightBitmask = 0b00100000;

  uint8_t currentValue = in8(registerAddress) & 0b00011111; // Register ohne Ampelfarben

  if (heightvalue > 3500) {
    out8(registerAddress, currentValue | redLightBitmask);
  } else if (heightvalue < 2600) {
    out8(registerAddress, currentValue | greenLightBitmask);
  } else {
    out8(registerAddress, currentValue | yellowLightBitmask);
  }
}

uint16_t getHeight(void) {
  static const uint16_t baseAddress = 0x320;
  static const uint16_t readLowAddressOffset = 0x2;
  static const uint16_t startConversionAddressOffset = 0x2;
  static const uint16_t readHighAddressOffset = 0x3;
  static const uint16_t startConversionOpCode = 0x10;
  static const uint16_t only12BitBitmask = 0x0FFF;

  uint16_t height;

  // write opcode to start conversion
  out8(baseAddress + startConversionAddressOffset, startConversionOpCode);

  //wait for conversion to complete
  usleep(10);

  //read low bytes
  height = in8(baseAddress + readLowAddressOffset);

  //read high bytes
  height |= (uint16_t)in8(baseAddress + readHighAddressOffset) << 8;

  // height sensor value is only 12 bit
  height &= only12BitBitmask;

  return height;
}

int main(int argc, char *argv[]) {

  static const uint16_t ioControlAddress = 0x303;
  static const uint8_t ioControlBitmask  = 0b10001010;
  uint16_t heightValue;

  /* Zugriffsrechte von QNX fuer diesen Thread, auf die Hardware erbitten. */
  if( ThreadCtl(_NTO_TCTL_IO_PRIV,0) == -1 ){
      cout << "Can't get Hardware access, therefore can't do anything." << endl;
  }

  /* IO Register als Eingänge bzw. Ausgänge definieren. */
  out8(ioControlAddress, ioControlBitmask);

  while (true) {
    heightValue = getHeight();
    cout << heightValue << endl;
    setLights(heightValue);
    usleep(250000);
  }

  return EXIT_SUCCESS;
}
