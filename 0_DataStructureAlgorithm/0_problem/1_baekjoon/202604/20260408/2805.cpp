#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	long n, m, max, start, end, result = 0;
	cin >> n >> m;

	vector<long> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	start = 1;
	max = *max_element(list.begin(), list.end());
	end = max;

	while (start <= end)
	{
		long mid = (start + end) / 2;
		long remainCm = 0;

		for (auto tree : list)
		{
			long remain = tree - mid;

			if (remain > 0)
				remainCm += remain;
		}

		if (remainCm >= m)
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