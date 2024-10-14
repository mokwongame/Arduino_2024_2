#include "Buzzer.h"

#define DEF_BUZZER_PORT (5)

Buzzer buzzer;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT); // 부저는 OUTPUT으로 선택
  buzzer.setPort(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 부저 소리내는 함수: tone()
  //tone(5, 523, 2000); // 5번 포트에 510 Hz를 3000 msec 동안 부저를 연주
  //tone(5, 262, 2000);
  buzzer.play(NOTE_DO, 2000);
  delay(2000);
  buzzer.play(NOTE_RE, 2000);
  delay(2000);
  delay(3000);
}
