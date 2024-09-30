#include "LightSensor.h"

LightSensor lightSensor;

void setup() {
  // put your setup code here, to run once:
  lightSensor.setPort(A2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nLight = lightSensor.getLightStep();
  Serial.println("light step = " + String(nLight));
  delay(1000);
}
