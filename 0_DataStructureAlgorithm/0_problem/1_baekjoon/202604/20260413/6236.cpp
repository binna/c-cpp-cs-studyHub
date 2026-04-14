#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, start, end = 0, result = 0;
	cin >> n >> m;

	vector<int> moneys(n);

	for (int i = 0; i < n; i++)
	{
		cin >> moneys[i];
		end += moneys[i];
	}

	start = *max_element(moneys.begin(), moneys.end());

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int haveMoney = 0;
		int cnt = 0;

		for (auto money : moneys)
		{
			if (haveMoney < money)
			{
				haveMoney = mid;
				cnt++;
			}
			haveMoney -= money;
		}

		if (cnt <= m)
		{
			result = mid;
			end = mid - 1;
			continue;
		}
		start = mid + 1;
	}

	cout << result;

	return 0;
}