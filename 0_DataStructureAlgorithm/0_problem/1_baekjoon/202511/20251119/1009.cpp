#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		long value = 1;
		for (int i = 0; i < b; i++)
		{
			value = (value * a) % 10;
		}

		int result = value == 0 ? 10 : value;
		cout << result << '\n';
	}

	return 0;
}