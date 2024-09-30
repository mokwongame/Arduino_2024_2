#include "LightSensor.h"

LightSensor lightSensor;

void setup() {
  // put your setup code here, to run once:
  lightSensor.setPort(A2); // 사진에서 분홍색 선을 A2에 연결
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nLight = lightSensor.getLightStep();
  Serial.println("light step = " + String(nLight));
  LightType nType = lightSensor.getLightType();
  Serial.println("light type = " + String(int(nType)));
  String str = lightSensor.typeToStr(nType);
  Serial.println("light = " + str);
  delay(1000);
}
