#include <iostream>
using namespace std;

int main(void)
{
	char name[100];
	char lang[100];

	cout << "이름은 무엇입니까?";
	cin >> lang;

	cout << "좋아하는 프로그래밍 언어는 무엇인가요?";
	cin >> lang;

	cout << "내 이름은 " << name << "입니다\n";
	cout << "내가 제일 좋아하는 언어는 " << lang << "입니다\n" << endl;

	cout << sizeof(name) << ", " << sizeof(lang);
	return 0;
}