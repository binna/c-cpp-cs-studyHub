#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	long long k, n, start, end, mid, max, result = 0;
	cin >> k >> n;

	vector<long long> lanList(k);

	for (int i = 0; i < k; i++)
	{
		cin >> lanList[i];
	}

	max = *(max_element(lanList.begin(), lanList.end()));
	start = 1;
	end = max;

	while (start <= end)
	{
		mid = (start + end) / 2;
		long long cnt = 0;

		for (auto lan : lanList)
		{
			cnt += lan / mid;
		}

		if (cnt < n)
		{
			end = mid - 1;
			continue;
		}

		result = mid;
		start = mid + 1;
	}

	cout << result;

	return 0;
}