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
#define PORT_BTN (5)  // push button의 port 번호

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

// 버튼 누르면 true를 return
bool getButton() {
  int nInput = digitalRead(PORT_BTN);
  delay(100); // 100 msec 지연
  if (nInput == LOW) return true; // 버튼 누름
  else return false; // 버튼 누르지 않음
}

void setup() {
  // put your setup code here, to run once:
  initLed();
  // digital port에 출력을 LOW(접지, 0V)로 쓰기
  turnRgb(false, false, false);
  // digital port를 입력으로 사용: PULLUP은 전압을 보드의 내부 전원으로 만든 5V로 올리기
  pinMode(PORT_BTN, INPUT_PULLUP);
  // Serial port 초기화(시작하기)
  Serial.begin(9600);  // 속도 9600 bps로 시작하기
}

void loop() {
  // digital port에서 입력을 읽기: 평상시 5V, 버튼 누르면 0V가 입력됨
  bool bPress = getButton();
  if (bPress) Serial.println("pressed");
}
