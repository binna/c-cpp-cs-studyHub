#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjectCnt;
public:
	SoSimple()
	{
		simObjectCnt++;
		cout << simObjectCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoSimplex
{
private:
	static int cmxObjectCnt;
public:
	SoSimplex()
	{
		cmxObjectCnt++;
		cout << cmxObjectCnt << "��° SoSmplex ��ü - ������" << endl;
	}

	SoSimplex(const SoSimplex& copy)
	{
		cmxObjectCnt++;
		cout << cmxObjectCnt << "��° SoSimplex ��ü - ���� ������" << endl;
	}
};

int SoSimple::simObjectCnt;
int SoSimplex::cmxObjectCnt;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoSimplex cmx1;
	SoSimplex cmx2 = cmx1;
	SoSimplex();

	cout << &cmx2 << endl;

	return 0;
}