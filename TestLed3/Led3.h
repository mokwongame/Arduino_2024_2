#pragma once

#define DEF_RLED_PORT	(2)
#define DEF_GLED_PORT	(3)
#define DEF_BLED_PORT	(4)

class Led3
{
public:
	Led3(void)
	{
		setPort(DEF_RLED_PORT, DEF_GLED_PORT, DEF_BLED_PORT);
	}
	~Led3()	{}

	setPort(int nPortR, int nPortG, int nPortB)
	{
		m_nPortR = nPortR;
		m_nPortG = nPortG;
		m_nPortB = nPortB;
	}

	void setup(void)
	{
		pinMode(m_nPortR, OUTPUT);
		pinMode(m_nPortG, OUTPUT);
		pinMode(m_nPortB, OUTPUT);
	}

	void turnLed(bool bR, bool bG, bool bB)
	{
		digitalWrite(m_nPortR, (bR) ? HIGH : LOW); // bR�� true�̸�, HIGH; bR�� false�̸� LOW
		digitalWrite(m_nPortG, (bG) ? HIGH : LOW);
		digitalWrite(m_nPortB, (bB) ? HIGH : LOW);
	}

protected:
	int m_nPortR;
	int m_nPortG;
	int m_nPortB;
};