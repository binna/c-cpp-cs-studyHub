#include <iostream>
using namespace std;

namespace BestComImpl
{
	void SimpleFunc(void)
	{
		cout << "BestComImpl�� ������ �Լ�" << endl;
	}
}

namespace ProgComImpl
{
	void SimpleFunc(void)
	{
		cout << "ProgComImpl�� ������ �Լ�" << endl;
	}
}

int main(void)
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
}