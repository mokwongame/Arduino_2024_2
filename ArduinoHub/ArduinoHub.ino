#include "ArduinoHub.h"

#define SERIAL_BPS (9600)

ArduinoHub arduinoHub;  // ArduinoHub 클래스(객체의 설계도)의 인스턴스(객체의 구현물)를 arduinoHub으로 선언

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  arduinoHub.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  arduinoHub.start();
}
