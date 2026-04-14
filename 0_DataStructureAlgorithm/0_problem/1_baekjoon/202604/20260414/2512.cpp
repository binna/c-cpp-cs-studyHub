#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	long n, m, start, end, max, result = 0;
	cin >> n;

	vector<long> budgets(n);

	for (long i = 0; i < n; i++)
	{
		cin >> budgets[i];
	}

	cin >> m;

	start = 1;
	end = *max_element(budgets.begin(), budgets.end());

	while (start <= end)
	{
		long mid = (start + end) / 2;
		long sum = 0;

		for (auto budget : budgets)
		{
			if (budget < mid)
			{
				sum += budget;
				continue;
			}

			sum += mid;
		}

		if (sum < m)
		{
			start = mid + 1;
			result = mid;
			continue;
		}

		end = mid - 1;
	}

	cout << result;

	return 0;
}