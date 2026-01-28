#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	long long k, n, start, end, mid, max, result;
	cin >> k >> n;

	vector<long long> lans(k);

	for (int i = 0; i < k; i++)
	{
		cin >> lans[i];
	}

	mid = 0;
	result = 0;

	max = *(max_element(lans.begin(), lans.end()));
	start = 1;
	end = max;

	while (start <= end)
	{
		int cnt = 0;
		mid = (start + end) / 2;

		for (auto lan : lans)
		{
			cnt += (lan / mid);
		}

		if (cnt < n)
		{
			end = mid - 1;
			continue;
		}

		if (cnt >= n)
		{
			if (result < mid)
				result = mid;
		}

		start = mid + 1;
	}

	cout << result;

	return 0;
}