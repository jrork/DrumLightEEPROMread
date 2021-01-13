/*
 * Tool to read the EEPROM values that are stored for the DrumLight program
 */

#include <EEPROM.h>
#include "drums.h"

drumLight myDrumLight = {Bass5, 62223, 100, 50, 35, 1, 2};  

void setup()
{  
  
  Serial.begin(74880); //Serial communication to display data
  Serial.printf("Drum id before EEPROM read: %d\n", myDrumLight.drumId);
  Serial.printf("Color value before EEPROM read: %d\n", myDrumLight.color);
  Serial.printf("Brightness value before EEPROM read: %i\n", myDrumLight.brightness);
  Serial.printf("Threshold value before EEPROM read: %i\n", myDrumLight.threshold);
  Serial.printf("Delay time value before EEPROM read: %i\n", myDrumLight.delayValue);
  Serial.printf("Trigger Mode value before EEPROM read: %i\n", myDrumLight.triggerMode);
  Serial.printf("Pixel count value before EEPROM read: %i\n", myDrumLight.pixelCount);

  char* myDrumLightBytes = reinterpret_cast<char*>(&myDrumLight);
  const uint32_t myDrumLightSize = sizeof(myDrumLight);
  EEPROM.begin(myDrumLightSize);  

  for(int index = 0; index < myDrumLightSize; index++){
    myDrumLightBytes[index] = EEPROM.read(index);
  }
  memcpy(&myDrumLight, myDrumLightBytes, sizeof(drumLight));
  
  Serial.printf("Drum id after EEPROM read: %d\n", myDrumLight.drumId);
  Serial.printf("Color value after EEPROM read: %d\n", myDrumLight.color);
  Serial.printf("Brightness value after EEPROM read: %i\n", myDrumLight.brightness);
  Serial.printf("Threshold value after EEPROM read: %i\n", myDrumLight.threshold);
  Serial.printf("Delay time value after EEPROM read: %i\n", myDrumLight.delayValue);
  Serial.printf("Trigger Mode value after EEPROM read: %i\n", myDrumLight.triggerMode);
  Serial.printf("Pixel count value after EEPROM read: %i\n", myDrumLight.pixelCount);

}

void loop()
{
  delay(1000);   
}
