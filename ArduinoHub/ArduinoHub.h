#pragma once

#include "StringTok.h"
#include "Voltmeter.h"
#include "LightSensor.h"
#include "Led3.h"
#include "Buzzer.h"

/* ArduinoHub의 명령어 규칙
- 명령어의 끝에는 엔터('\n') 넣음
- 명령어가 있으면 엔터가 있음: 명령어 입력 여부를 판단
- 전압 읽기(토큰 2개): get volt
- 조도 스텝 읽기(토큰 2개): get lightstep
- 조도 상태(dark, ambient, bright) 읽기(토큰 2개): get light
- 3색 LED 켜기(color: red, green, blue, cyan, magenta, yellow, white, off; 토큰 3개): set led color
- 부저 켜기(note: do, re, mi, fa, sol, ra, si; 토큰 3개): play note #time
- 부저 끄기(토큰 2개): play off
*/

class ArduinoHub
{
public:
	ArduinoHub(void) {}
	~ArduinoHub() {}

	void setup(void) // void setup()도 가능하게 됨
	{
		m_voltmeter.setPort(A0);
		m_lightSensor.setPort(A1);
		m_led3.setPort(2, 3, 4);
		m_led3.setup();
		m_buzzer.setPort(5);
		m_buzzer.setup();
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
	Voltmeter m_voltmeter; // 전압계
	LightSensor m_lightSensor; // 조도 센서
	Led3 m_led3;	// 3색 LED
	Buzzer m_buzzer;	// 부저

	void exeCmd(void)
	{
		// #1 토큰(token, 표식) 추출
		String sToken = getToken(); // cutToken(): 현재 문자열에서 처음 토큰을 잘라냄(cut); 문자열의 크기는 잘라낸 만큼 줄어듬
		//Serial.println(sToken); // 디버깅용 코드
		if (sToken == "get") // get에 대한 명령어 처리
		{
			exeGet();
		}
		else if (sToken == "set") exeSet();
		else if (sToken == "play") exePlay();
		else // 잘못된 명령어
			printError(sToken);
	}

	void exeGet(void)
	{
		// #2 토큰 추출
		String sToken = getToken();
		if (sToken == "volt") exeVolt(); // 전압 읽기
		else if (sToken == "lightstep") exeLightStep();
		else if (sToken == "light") exeLight();
		else printError(sToken);
	}

	void exeSet(void)
	{
		// #2 토큰 추출
		String sToken = getToken();
		if (sToken == "led") exeLed();
		else printError(sToken);
	}

	void exePlay(void)
	{
		// #2 토큰 추출
		String sToken = getToken();
		if (sToken == "do") exePlayNote(NOTE_DO);
		else printError(sToken);
	}

	void exePlayNote(int nNote)
	{
		// #3 토큰 추출
		String sToken = getToken();
		// 문자열 -> 정수로 변환
	}

	void exeLed(void)
	{
		// #3 토큰 추출
		String sToken = getToken();
		if (sToken == "red") m_led3.turnLed(true, false, false);
		else if (sToken == "green") m_led3.turnLed(false, true, false);
		else if (sToken == "off") m_led3.turnLed(false, false, false);
		else printError(sToken);
	}

	void exeVolt(void)
	{
		double volt = m_voltmeter.getVolt();
		Serial.println(String(volt, 10)); // 10 의미: 소수점 이하 10자리까지 문자열로 변환
	}

	void exeLightStep(void)
	{
		int nStep = m_lightSensor.getLightStep();
		Serial.println(nStep);
	}

	void exeLight(void)
	{
		LightType nLight = m_lightSensor.getLightType();
		Serial.println(m_lightSensor.typeToStr(nLight));
	}

	// 자주 쓰는 코드는 함수로 구현
	String getToken(void)
	{
		String sToken = m_stInput.cutToken().toString();
		return sToken;
	}

	void printError(const String& sToken) // const: 상수(함수 입력에 쓰면 입력 변수 sToken이 함수 내에서 상수 취급); &: 레퍼런스(포인터와 같은 역할이지만 포인터가 아닌 변수로 쓰임)로 입력 받음
	{
		// 공백인 토큰은 오류가 아님
		if (sToken.length() == 0) return;
		Serial.println("wrong command: " + sToken);
		m_stInput.empty(); // 문자열 전체 비우기(empty)
	}
};