#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}

	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	// 1. �Ű����� ���� ������ ȣ��
	SimpleClass sc1;
	SimpleClass sc2{};

	sc1.ShowData();
	sc2.ShowData();

	// 2. �Ű����� �ִ� ������ ȣ��
	SimpleClass sc3(30);
	SimpleClass sc4{10, 20};

	sc3.ShowData();
	sc4.ShowData();

	// å ����
	// ���� �Լ��� ������ ����������(�Լ� �ۿ�) ����������,
	// �Ʒ��� ����ó�� �Լ� ���� ���������� ���� ����
	SimpleClass sc5();			// �Լ��� ���� ����
	SimpleClass mysc = sc5();
	mysc.ShowData();
	return 0;
}

SimpleClass sc5()
{
	SimpleClass sc(20, 30);
	return sc;
}