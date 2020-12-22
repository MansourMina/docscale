const byte interruptPin = 2;
volatile byte interruptCounter = 0;
int numberOfInterrupts = 0;

 
void setup() {
 
  Serial.begin(115200);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);
 
}
 
ICACHE_RAM_ATTR void handleInterrupt() {
  
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  interruptCounter++;
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);

  //TODO interrupt deaktivieren, reseten, bestimmte Zeit warten - interrupt wieder aktivieren
}
round(float x)
{
        float t;

        if (!isfinite(x))
                return (x);

        if (x >= 0.0) {
                t = floor(x);
                if (t - x <= -0.5)
                        t += 1.0;
                return (t);
        } else {
                t = floor(-x);
                if (t + x <= -0.5)
                        t += 1.0;
                return (-t);
        }
}

void loop() {
  

    if(interruptCounter>0){
      
      interruptCounter--;
      numberOfInterrupts++;
      Serial.print("An interrupt has occurred. Total: ");
      Serial.println(numberOfInterrupts);
    }
  
}
