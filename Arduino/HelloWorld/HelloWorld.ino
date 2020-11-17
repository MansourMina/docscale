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

HX711 scale;

uint8_t dataPin = 12;
uint8_t clockPin = 14;


void setup()
{
  Serial.begin(9600);
  Serial.println("Hello World");

// Scale.set_scale ohne Paramter, Ein Objekt (30 Gramm) auf die Waage legen und diesen Wert als Paramater in set scale geben.
//danach sollte 1 rauskommen, unten bei units dann * 30.
  scale.begin(dataPin, clockPin);
  
  scale.set_scale(13943.50);
  scale.tare();
  //scale.callibrate_scale(30);

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

void loop()
{
  
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(1)*30);
  delay(2000);

}

// END OF FILE
