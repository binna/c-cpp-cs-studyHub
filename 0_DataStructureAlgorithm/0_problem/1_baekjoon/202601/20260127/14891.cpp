#include <iostream>

using namespace std;

int alphabet[26] = { 0, };

int main(void)
{
	string s;
	cin >> s;

	for (auto word : s)
	{
		alphabet[word - 'a']++;
	}

	for (auto cnt : alphabet)
	{
		cout << cnt << ' ';
	}

	return 0;
}