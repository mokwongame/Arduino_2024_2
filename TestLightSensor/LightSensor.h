#pragma once

#include "Voltmeter.h"

#define DEF_LIGHT_SENSOR_PORT	(A1)

class LightSensor: public Voltmeter // Voltmeter�� public���� ��� ����(:)
{
public:
	LightSensor(void)
	{
		setPort(DEF_LIGHT_SENSOR_PORT); // setPort()�� LightSensor�� ������� ����� �ƴ� -> ������ Voltmeter�� public���� ��ӹ޾Ƽ� public �׷쿡 ���� setPort()�� ��� ����
	}
	~LightSensor()
	{}

	int getLightStep(void) const
	{
		return getVoltStep(); // getVoltStep() �Լ��� Voltmeter�� ���ǵ� ��� �Լ�
	}

protected:
};