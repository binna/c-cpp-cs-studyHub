#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> result(n, 0);

	for (int i = 0; i < n; i++)
	{
		int leftCnt;
		cin >> leftCnt;

		int zeroCnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (zeroCnt == leftCnt && result[j] == 0)
			{
				result[j] = i + 1;
				break;
			}

			if (result[j] == 0)
				zeroCnt++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}