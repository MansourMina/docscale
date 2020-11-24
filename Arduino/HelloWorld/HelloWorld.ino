//
//    FILE: HX_kitchen_scale.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: HX711 demo
//     URL: https://github.com/RobTillaart/HX711
//
// HISTORY:
// 0.1.0    2020-06-16 initial version
//

#include "HX711.h"
#include <Wire.h> //Bibliothek für die Arduino IDE <= 1.6.5
#include "SSD1306Wire.h" //Display Bibliothek
#include "OLEDDisplayUi.h" //Display Bibliothek

SSD1306Wire  display(0x3c, D1, D2);
OLEDDisplayUi ui ( &display );

HX711 scale;

uint8_t dataPin = 12;
uint8_t clockPin = 14;

void helloFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(0, 0, "0");
}

FrameCallback frames[] = { helloFrame};
const int frameCount = 1;


void setup()
{
 
   ui.setTargetFPS(60);
   ui.setFrames(frames, frameCount);
   ui.init();
   display.flipScreenVertically();
  scale.begin(dataPin, clockPin);
  scale.set_scale(13943.50);
  scale.tare();
  scale.callibrate_scale(30);

/*
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  
  Serial.println("\nEmpty the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
  
  scale.tare();
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  Serial.println("\nPut a 1 kg in the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
  scale.callibrate_scale(1000, 5);
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  Serial.println("\nScale is callibrated, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
  
*/
}

void loop(OLEDDisplay *display){
  //display->drawString(0, 0,String(scale.get_units(1)*30));

  
  int remainingTimeBudget = ui.update();
}


// END OF FILE
