// Problem 1001
// https://www.acmicpc.net/problem/1001
//#include <iostream>
//using namespace std;
//
//int Minus(int num1, int num2)
//{
//	return num1 - num2;
//}
//
//int main(void)
//{
//	int input1, input2;
//
//	cin >> input1;
//	cin >> input2;
//
//	cout << Minus(input1, input2);
//	
//	return 0;
//}

// Problem 10998
// https://www.acmicpc.net/problem/10998
//#include <iostream>
//using namespace std;
//
//int Multiplication(int num1, int num2)
//{
//	return num1 * num2;
//}
//
//int main(void)
//{
//	int input1, input2;
//
//	cin >> input1;
//	cin >> input2;
//
//	cout << Multiplication(input1, input2);
//	return 0;
//}

// Problem 1008
// https://www.acmicpc.net/problem/1008
#include <iostream>
using namespace std;

double Division(double num1, double num2)
{
	return num1 / num2;
}

int main(void)
{
	int input1, input2;

	cin >> input1;
	cin >> input2;

	cout.precision(9);			// �Ǽ��� n�ڸ� ��ŭ�� ����ϰ� �Ѵ�.
	cout << fixed;				// ���� �Ҽ��� ǥ��� fixed�� ����� ���ĺ��ʹ� cout.precision(n)���� ���� n�� ��ŭ �Ҽ��� �Ʒ� �ڸ����� ���

	cout << Division(input1, input2);

	cout.unsetf(ios::fixed);	// fixed�� ����

	return 0;
}