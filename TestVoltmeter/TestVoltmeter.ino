#include "Voltmeter.h" // 컴파일러에게 지시해서(#) 헤더 파일 Voltmeter.h를 포함시킴(include); "..." 의미는 헤더 파일을 검색할 때 현재 폴더만 검색한다는 뜻

Voltmeter voltmeter; // 클래스(객체의 설계도) Voltmeter의 인스턴스(변수: 객체의 구현물)로 voltmeter를 선언

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // 9600 bps 속도로 Serial 시작(begin)
  voltmeter.setPort(A1); // A1 포트를 전압계로 활용
}

void loop() {
  // put your main code here, to run repeatedly:
  // 코드 형태로 전압계 활용
  // ADC 변동 범위: 0~1023(2^10 - 1) -> 전압 변동 범위: 0V~5V
  int nVolt = analogRead(A0);  // A0인 아날로그 포트에서 읽기(read): ADC룰 써서 아날로그(analog) 전압을 디지털(digital) 숫자로 변경(converter)
  Serial.println(nVolt);
  double volt = nVolt / 1023. * 5.;
  Serial.println("volt @ A0 = " + String(volt)); // String(.): 변수를 문자열(string)로 자료형을 강제로 선정(type casting)

  // 클래스로 전압계 활용
  nVolt = voltmeter.getVoltStep();
  volt = voltmeter.getVolt();
  Serial.println("volt @ A1 = " + String(volt));

  delay(1000);  // 1000 msec 지연(delay) 후에 그 다음 명령 실행
}
