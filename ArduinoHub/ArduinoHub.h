#pragma once

#include "StringTok.h"
#include "Voltmeter.h"
#include "LightSensor.h"

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
			// 구문 분석(parsing)
		}
	}

protected:
	StringTok m_stInput; // Serial로 입력받은 문자를 저장받는 StringTok의 인스턴스
};