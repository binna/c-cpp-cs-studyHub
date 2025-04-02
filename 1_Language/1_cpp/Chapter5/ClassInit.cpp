#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		:num1(n1), num2(n2)
	{
		cout << "SoSimple(int n1, int n2)" << endl;
	}
	SoSimple(SoSimple& copy)
		:num1(copy.num1), num2(copy.num2)
	{
		cout << "Colled SoSimple(SoSimple& copy)" << endl;
	}
	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};
int main(void)
{
	SoSimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ���� " << sizeof(sim1) << endl;

	SoSimple sim2 = sim1;		// SoSimple(sim1); ���� ��ȯ
	cout << "���� �� �ʱ�ȭ ���� " << sizeof(sim2) << endl;
	sim1.ShowSimpleData();

	return 0;
}