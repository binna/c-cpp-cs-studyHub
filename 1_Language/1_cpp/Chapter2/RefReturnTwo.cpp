#include <iostream>
using namespace std;

// return int&
// ȣ���ڰ� ���ϰ��� ��� �޴��Ŀ� ����
// ���� �����ϰ� �������� �����ϰ�
int& RefFuncOne(int& ref)
{
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefFuncOne(num1);
	int& num3 = RefFuncOne(num1);

	num1++;
	num2 += 100;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl << endl << endl;

	return 0;
}