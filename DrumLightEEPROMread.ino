/*
 * Tool to read the EEPROM values that are stored for the DrumLight program
 */

#include <EEPROM.h>
#include "drums.h"
#include "modes.h"

struct drumLight {
  drumID drumId;
  uint32_t color;
  uint8_t brightness;
  uint32_t threshold;
  uint8_t delayValue;
  modeID triggerMode;
  uint8_t pixelCount;
};

drumLight myDrumLight = {Bass5, 62223, 100, 50, 35, offMode, 2};  

void setup()
{  
  
  Serial.begin(74880); //Serial communication to display data
  Serial.printf("Drum id before EEPROM read: %s\n", DrumText[myDrumLight.drumId]);
  Serial.printf("Color value before EEPROM read: %d\n", myDrumLight.color);
  Serial.printf("Brightness value before EEPROM read: %i\n", myDrumLight.brightness);
  Serial.printf("Threshold value before EEPROM read: %i\n", myDrumLight.threshold);
  Serial.printf("Delay time value before EEPROM read: %i\n", myDrumLight.delayValue);
  Serial.printf("Trigger Mode value before EEPROM read: %s\n", ModeText[myDrumLight.triggerMode]);
  Serial.printf("Pixel count value before EEPROM read: %i\n", myDrumLight.pixelCount);
  Serial.println();

  char* myDrumLightBytes = reinterpret_cast<char*>(&myDrumLight);
  const uint32_t myDrumLightSize = sizeof(myDrumLight);
  EEPROM.begin(myDrumLightSize);  

  for(int index = 0; index < myDrumLightSize; index++){
    myDrumLightBytes[index] = EEPROM.read(index);
  }
  memcpy(&myDrumLight, myDrumLightBytes, sizeof(drumLight));
  
  Serial.printf("Drum id after EEPROM read: %s\n", DrumText[myDrumLight.drumId]);
  Serial.printf("Color value after EEPROM read: %d\n", myDrumLight.color);
  Serial.printf("Brightness value after EEPROM read: %i\n", myDrumLight.brightness);
  Serial.printf("Threshold value after EEPROM read: %i\n", myDrumLight.threshold);
  Serial.printf("Delay time value after EEPROM read: %i\n", myDrumLight.delayValue);
  Serial.printf("Trigger Mode value after EEPROM read: %s\n", ModeText[myDrumLight.triggerMode]);
  Serial.printf("Pixel count value after EEPROM read: %i\n", myDrumLight.pixelCount);

}

void loop()
{
  delay(1000);   
}
