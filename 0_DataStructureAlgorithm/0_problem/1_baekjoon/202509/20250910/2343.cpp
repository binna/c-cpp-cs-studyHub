#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int start = -1;
	int end = 0;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		end += v[i];

		if (start < v[i])
			start = v[i];
	}

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0;
		int count = 0;

		for (int i = 0; i < n; i++)
		{
			if (sum + v[i] > mid)
			{
				count++;
				sum = 0;
			}
			sum += v[i];
		}

		if (sum != 0)
			count++;

		if (count > m)
		{
			start = mid + 1;
			continue;
		}

		end = mid - 1;
	}

	cout << start;
	return 0;
}