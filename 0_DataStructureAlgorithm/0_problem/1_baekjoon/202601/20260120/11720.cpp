#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	string inputValue;

	long result = 0;

	cin >> n >> inputValue;

	for (int i = 0; i < n; i++)
	{
		int targetNum = inputValue[i] - '0';
		result += targetNum;
	}

	cout << result;

	return 0;
}