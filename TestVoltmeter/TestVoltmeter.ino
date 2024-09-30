void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // 9600 bps 속도로 Serial 시작(begin)
}

void loop() {
  // put your main code here, to run repeatedly:
  // ADC 변동 범위: 0~1023(2^10 - 1) -> 전압 변동 범위: 0V~5V
  int nVolt = analogRead(A0);  // A0인 아날로그 포트에서 읽기(read): ADC룰 써서 아날로그(analog) 전압을 디지털(digital) 숫자로 변경(converter)
  Serial.println(nVolt);
  double volt = nVolt / 1023. * 5.;
  Serial.println("volt = " + String(volt)); // String(.): 변수를 문자열(string)로 자료형을 강제로 선정(type casting)
  delay(1000);  // 1000 msec 지연(delay) 후에 그 다음 명령 실행
}
