#include "Led3.h"

Led3 led3;

void setup() {
  // put your setup code here, to run once:
  led3.setPort(2, 3, 4);
  led3.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  led3.turnLed(true, false, false);
  delay(1000);
  led3.turnLed(false, true, false);
  delay(1000);
  led3.turnLed(false, false, true);
  delay(1000);
  led3.turnLed(false, false, false);
  delay(1000);
}
