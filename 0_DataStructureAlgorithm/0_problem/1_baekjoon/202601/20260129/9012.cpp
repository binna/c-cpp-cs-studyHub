#include <iostream>

using namespace std;

int main(void)
{
	int startCnt, n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string temp, result;
		cin >> temp;

		startCnt = 0;

		result = "YES";

		for (auto c : temp)
		{
			if (c == '(')
			{
				startCnt++;
				continue;
			}

			startCnt--;

			if (startCnt < 0)
			{
				result = "NO";
				break;
			}
		}

		if (startCnt > 0)
			result = "NO";

		cout << result << "\n";
	}

	return 0;
}