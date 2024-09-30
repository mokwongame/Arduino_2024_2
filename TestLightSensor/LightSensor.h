#pragma once

#include "Voltmeter.h"

#define DEF_LIGHT_SENSOR_PORT	(A1)

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

protected:
};