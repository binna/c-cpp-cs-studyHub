#include <iostream>
using namespace std;

class SoSimple
{
public:
	static int simObjectCnt;

	SoSimple()
	{
		simObjectCnt++;
	}
};

int SoSimple::simObjectCnt;

int main(void)
{
	cout << SoSimple::simObjectCnt << "��° SoSimple ��ü" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << endl << endl << SoSimple::simObjectCnt << "��° SoSimple ��ü" << endl;
	cout << sim1.simObjectCnt << "��° SoSimple ��ü" << endl;
	cout << sim2.simObjectCnt << "��° SoSimple ��ü" << endl;
}