#include <iostream>
#include <string>
using namespace std;

int main()
{
	int index;
	string text;
	int result = 0;

	cin >> index;
	cin >> text;

	for (int i = 0; i < index; i++)
	{
		int temp = text[i] - '0';
		result += temp;
	}

	cout << result;

	return 0;
}