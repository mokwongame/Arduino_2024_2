// 헤더(header) 파일의 시작
#pragma once // 현재 헤더 파일을 한번만(once) 포함시키도록 컴파일러에게 지시(#)하여 개발자에게 컴파일러를 점진적으로(pragmatic) 맞춤

#define DEF_VOLT_PORT	(A0)

// 객체 프로그래밍의 시작은 클래스!
class Voltmeter // 파일명과 클래스명은 동일하기를 권고
{
public: // public 그룹을 정의(:); public은 클래스 외부에서 접근이 가능한 멤버(변수 혹은 함수)
	// 생성자와 소멸자
	Voltmeter(void) // 클래스명과 동일한 함수명은 생성자; 클래스가 생성될 때(인스턴스가 만들어질 때) 자동적으로 호출되는 함수
	{
		setPort(DEF_VOLT_PORT); // Voltmeter 클래스가 생성될 때 setPort() 함수를 자동으로 호출
	}
	~Voltmeter() // ~(C 언어에서 NOT)으로 시작하는 함수(\함수명은 클래스명)는 소멸자; 인스턴스가 소멸될 때 자동으로 호출되는 함수(클래스 사용후에 값을 저장하거나 메모리를 해제할 때 사용)
	{

	}

	// 함수 정의 끝부분의 const(상수: constant number) 의미: 이 함수를 호출해도 내부 멤버 변수를 변경하지 않음(상수로 취급)
	int getVoltStep(void) const
	{
		int nVolt = analogRead(m_nPort);
		return nVolt;
	}

	double getVolt(void) const
	{
		int nVolt = getVoltStep();
		double volt = nVolt / 1023. * 5.;
		return volt;
	}

	void setPort(int nPort)
	{
		m_nPort = nPort;
	}

private: // private 그룹; 외부에서 접근 불가, 멤버를 클래스 내부적으로만 사용; 정말 보호해야 할 멤버만 예외적으로 사용

protected: // protected 그룹; 외부에서 접근 불가, 상속하면 접근 가능
	int m_nPort; // 전압계를 연결할 포트 저장
};