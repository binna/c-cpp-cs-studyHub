#include <iostream>
using namespace std;

int main(void)
{
	char name[100];
	char lang[100];

	cout << "�̸��� �����Դϱ�?";
	cin >> lang;

	cout << "�����ϴ� ���α׷��� ���� �����ΰ���?";
	cin >> lang;

	cout << "�� �̸��� " << name << "�Դϴ�\n";
	cout << "���� ���� �����ϴ� ���� " << lang << "�Դϴ�\n" << endl;

	cout << sizeof(name) << ", " << sizeof(lang);
	return 0;
}