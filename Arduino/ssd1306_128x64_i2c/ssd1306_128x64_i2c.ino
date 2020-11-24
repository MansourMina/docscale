#include <Wire.h> //Bibliothek für die Arduino IDE <= 1.6.5
#include "SSD1306Wire.h" //Display Bibliothek
#include "OLEDDisplayUi.h" //Display Bibliothek
//Initialisieren des Displays
//D1 - SDA
//D2 - SCL
SSD1306Wire  display(0x3c, D1, D2);
//Initialisieren des Objektes für die Oberfläche des Displays.
//Es lassen sich mehrere Frames damit erzeugen welche in einem
//definierten Interval angezeigt werden.
OLEDDisplayUi ui ( &display );
//Funktion zum anzeigen des Textes "Hello World!" auf dem Display.
void helloFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(0, 0, "0");
}
//Array mit den Frames für das Display.
//Jeder Eintrag in diesem Array repräsentiert eine Darstellung
//des Displays.
FrameCallback frames[] = { helloFrame};
//Anzahl der maximalen Frames welche angezeigt werden sollen.
const int frameCount = 1;
void setup() {
   //Setzen der Bildwiederholungsfrequenz
   ui.setTargetFPS(60);
   //Setzen der Frames sowie die Anzahl der Frames.
   ui.setFrames(frames, frameCount);
   //Initialisieren der Oberfläche.
   ui.init();
   //Bildschirm drehen, ansonsten ist die Darstellung auf dem Kopf.
   display.flipScreenVertically();
}
void loop() {
 int remainingTimeBudget = ui.update();
}
