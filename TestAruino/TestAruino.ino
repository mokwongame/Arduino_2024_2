/* Push button으로 3색 LED 제어
1. 처음에는 LED가 모두 off
2. 버튼 누르면 R on
3. 그 다음 버튼 누르면 G on, R off
4. 그 다음 버튼 누르면 B on, G off
5. 그 다음 버튼 누르면 RGB on
6. 그 다음 버튼 누르면 RGB off
 */

#define PORT_R (2)
#define PORT_G (3)
#define PORT_B (4)

void initLed() {
  // digital port를 출력(output)으로 사용하는 모드(mode)로 선택
  pinMode(PORT_R, OUTPUT);
  pinMode(PORT_G, OUTPUT);
  pinMode(PORT_B, OUTPUT);
}

void turnLed(int nPort, bool bOn) {
  if (bOn) digitalWrite(nPort, HIGH);
  else digitalWrite(nPort, LOW);
}

void turnRgb(bool bRed, bool bGreen, bool bBlue) {
  turnLed(PORT_R, bRed);
  turnLed(PORT_G, bGreen);
  turnLed(PORT_B, bBlue);
}

void setup() {
  // put your setup code here, to run once:
  initLed();
  // digital port에 출력을 LOW(접지, 0V)로 쓰기
  turnRgb(false, false, false);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);  // 1000 msec 동안 지연(delay)
  // digital port에 출력을 HIGH(전압이 높음, 5V)로 쓰기
  turnRgb(true, true, true);
  delay(1000);
  turnRgb(false, false, false);
}
