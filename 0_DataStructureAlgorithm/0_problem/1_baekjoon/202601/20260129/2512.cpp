#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, start, end, mid, money, result, max;
	cin >> n;

	vector<int> budgets(n);

	for (int i = 0; i < n; i++)
	{
		cin >> budgets[i];
	}

	cin >> m;

	mid = 0, result = 0;

	max = *(max_element(budgets.begin(), budgets.end()));
	start = 1;
	end = max;

	while (start <= end)
	{
		mid = (start + end) / 2;
		money = 0;

		for (auto budget : budgets)
		{
			if (budget < mid)
			{
				money += budget;
				continue;
			}
			money += mid;
		}

		if (money > m)
		{
			end = mid - 1;
			continue;
		}

		if (result < mid)
			result = mid;

		start = mid + 1;
	}

	cout << result;

	return 0;
}