#pragma once

#include "StringTok.h"
#include "Voltmeter.h"
#include "LightSensor.h"

/* ArduinoHub의 명령어 규칙
- 명령어의 끝에는 엔터('\n') 넣음
- 명령어가 있으면 엔터가 있음: 명령어 입력 여부를 판단
- 전압 읽기: get volt
- 조도 스텝 읽기: get lightstep
- 조도 상태(dark, ambient, bright) 읽기: get light
*/

class ArduinoHub
{
public:
	ArduinoHub(void) {}
	~ArduinoHub() {}

	void setup(void) // void setup()도 가능하게 됨
	{

	}

	void start(void) // ArduinoHub의 시작점
	{
		while (1) // 펌웨어는 보통 무한 루프로 돌림
		{
			// Serial에서 입력받은 문자를 m_stInput에 계속 붙여넣기(append)
			m_stInput.appendSerial();
			//Serial.println(m_stInput.toString()); // 디버깅용 코드(확인 코드); ,toString()을 호출하면 StringTok이 String으로 바뀌어 반환
			// 구문 분석(parsing)
			if (m_stInput.hasLine()) // hasLine(): 문자열에 엔터가 있는지 확인; 엔터가 있으면 명령어가 입력됨
				exeCmd(); // 명령어(command) 실행(execution)
			//delay(1000); // 디버깅용 코드
		}
	}

protected:
	StringTok m_stInput; // Serial로 입력받은 문자를 저장받는 StringTok의 인스턴스

	void exeCmd(void)
	{
		// 토큰(token, 표식) 추출
		String sToken = m_stInput.cutToken().toString(); // cutToken(): 현재 문자열에서 처음 토큰을 잘라냄(cut); 문자열의 크기는 잘라낸 만큼 줄어듬
		Serial.println(sToken); // 디버깅용 코드
	}
};