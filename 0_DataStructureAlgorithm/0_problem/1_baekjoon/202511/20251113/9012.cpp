#include <iostream>

using namespace std;

int main(void)
{
	int n, cnt;
	bool isSuccess;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		cnt = 0;
		isSuccess = true;

		for (auto ch : temp)
		{
			if (ch == '(')
			{
				cnt++;
				continue;
			}

			if (ch == ')')
			{
				if (cnt <= 0)
				{
					isSuccess = false;
					break;
				}
				cnt--;
				continue;
			}
		}

		if (cnt != 0)
			isSuccess = false;

		string result = isSuccess ? "YES\n" : "NO\n";

		cout << result;
	}

	return 0;
}