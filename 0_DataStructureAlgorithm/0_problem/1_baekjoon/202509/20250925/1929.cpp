#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> m >> n;

	vector<bool> result(n + 1, true);

	result[1] = false;
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < n; j++)
		{
			int num = i * j;

			if (num > n)
				break;

			result[num] = false;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (result[i])
			cout << i << '\n';
	}

	return 0;
} 