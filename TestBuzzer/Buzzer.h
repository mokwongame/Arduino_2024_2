#pragma once

#define DEF_BUZZER_PORT (5)
#define NOTE_DO		(523)
#define NOTE_RE		(587)

class Buzzer
{
public:
	Buzzer(void)
	{
		setPort(DEF_BUZZER_PORT);
	}
	~Buzzer() {}

	void setPort(int nPort)
	{
		m_nPort = nPort;
	}

	void play(int nNote, int nTime) // 부저 켜기: nNote(음의 높낮이, 주파수), nTime(연주 시간, msec)
	{
		tone(m_nPort, nNote, nTime);
	}

	void playOff(void) // 부저 끄기
	{
		noTone(m_nPort);
	}

protected:
	int m_nPort;
};