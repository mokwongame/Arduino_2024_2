// ���(header) ������ ����
#pragma once // ���� ��� ������ �ѹ���(once) ���Խ�Ű���� �����Ϸ����� ����(#)�Ͽ� �����ڿ��� �����Ϸ��� ����������(pragmatic) ����

#define DEF_VOLT_PORT	(A0)

// ��ü ���α׷����� ������ Ŭ����!
class Voltmeter // ���ϸ��� Ŭ�������� �����ϱ⸦ �ǰ�
{
public: // public �׷��� ����(:); public�� Ŭ���� �ܺο��� ������ ������ ���(���� Ȥ�� �Լ�)
	// �����ڿ� �Ҹ���
	Voltmeter(void) // Ŭ�������� ������ �Լ����� ������; Ŭ������ ������ ��(�ν��Ͻ��� ������� ��) �ڵ������� ȣ��Ǵ� �Լ�
	{
		setPort(DEF_VOLT_PORT); // Voltmeter Ŭ������ ������ �� setPort() �Լ��� �ڵ����� ȣ��
	}
	~Voltmeter() // ~(C ���� NOT)���� �����ϴ� �Լ�(\�Լ����� Ŭ������)�� �Ҹ���; �ν��Ͻ��� �Ҹ�� �� �ڵ����� ȣ��Ǵ� �Լ�(Ŭ���� ����Ŀ� ���� �����ϰų� �޸𸮸� ������ �� ���)
	{

	}

	// �Լ� ���� ���κ��� const(���: constant number) �ǹ�: �� �Լ��� ȣ���ص� ���� ��� ������ �������� ����(����� ���)
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

private: // private �׷�; �ܺο��� ���� �Ұ�, ����� Ŭ���� ���������θ� ���; ���� ��ȣ�ؾ� �� ����� ���������� ���

protected: // protected �׷�; �ܺο��� ���� �Ұ�, ����ϸ� ���� ����
	int m_nPort; // ���а踦 ������ ��Ʈ ����
};