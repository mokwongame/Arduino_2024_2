#pragma once

#include "Voltmeter.h"

#define DEF_LIGHT_SENSOR_PORT	(A1)
#define LIGHT_BRIGHT_LIMIT	(400)	// 밝은 빛의 한계
#define LIGHT_AMBIENT_LIMIT	(730)	// 자연광의 한계

// 조도 상태를 3가지로 구분: 0, 1, 2로 배정
enum class LightType
{
	DARK=0, AMBIENT, BRIGHT
};
// 밝음 = 230, 자연광 = 570, 어두움 = 890

class LightSensor: public Voltmeter // Voltmeter를 public으로 상속 받음(:)
{
public:
	LightSensor(void)
	{
		setPort(DEF_LIGHT_SENSOR_PORT); // setPort()는 LightSensor의 명시적인 멤버가 아님 -> 하지만 Voltmeter를 public으로 상속받아서 public 그룹에 속한 setPort()를 사용 가능
	}
	~LightSensor()
	{}

	int getLightStep(void) const
	{
		return getVoltStep(); // getVoltStep() 함수는 Voltmeter에 정의된 멤버 함수
	}

	LightType getLightType(void) const
	{
		int nLight = getLightStep();
		if (nLight < LIGHT_BRIGHT_LIMIT) return LightType::BRIGHT; // 밝은 조건
		else if (nLight < LIGHT_AMBIENT_LIMIT) return LightType::AMBIENT; // 자연광 조건
		else return LightType::DARK; // 어두운 조건
	}

protected:
};