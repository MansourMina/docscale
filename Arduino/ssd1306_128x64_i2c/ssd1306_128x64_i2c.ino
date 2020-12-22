#include "HX711.h"
#include <Wire.h> //Bibliothek für die Arduino IDE <= 1.6.5
#include "SSD1306Wire.h" //Display Bibliothek
#include "OLEDDisplayUi.h" //Display Bibliothek

HX711 scale;
uint8_t dataPin = 14;
uint8_t clockPin = 12;
const byte interruptPin = 2;
volatile byte interruptCounter = 0;


//Initialisieren des Displays
//D1 - SDA
//D2 - SCL

SSD1306Wire  display(0x3c, D1, D2);
//Initialisieren des Objektes für die Oberfläche des Displays.
//Es lassen sich mehrere Frames damit erzeugen welche in einem
//definierten Interval angezeigt werden.

OLEDDisplayUi ui ( &display );
//Funktion zum anzeigen des Textes "Hello World!" auf dem Display.
float gewicht= 0;

ICACHE_RAM_ATTR void handleInterrupt() {
  interruptCounter++;
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);

  //TODO interrupt deaktivieren, reseten, bestimmte Zeit warten - interrupt wieder aktivieren
}

void helloFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_24);
  
  char ausgabe[30];
  sprintf(ausgabe,"%.1f g" ,gewicht);
  
  display->drawString(0,0 , ausgabe);
}

//Array mit den Frames für das Display.
//Jeder Eintrag in diesem Array repräsentiert eine Darstellung
//des Displays.
FrameCallback frames[] = { helloFrame};

//Anzahl der maximalen Frames welche angezeigt werden sollen.

const int frameCount = 1;

void setup() {
 
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);
  scale.begin(dataPin, clockPin);
  scale.set_scale(171995.20);  //13943.50
  scale.tare();
  
 
   ui.setTargetFPS(60);
   ui.setFrames(frames, frameCount);
   ui.init();
   display.flipScreenVertically();


  
}

void loop() {
  
  Serial.print("UNITS: ");
  gewicht = scale.get_units(1)*370;
  delay(500);
  int remainingTimeBudget = ui.update();

  if(interruptCounter>0){
      scale.tare();
      interruptCounter= 0;
  }
}
