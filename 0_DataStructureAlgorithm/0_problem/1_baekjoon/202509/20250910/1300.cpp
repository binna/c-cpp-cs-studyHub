#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int start = 1, end = k;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0;

		for (int i = 1; i <= n; i++)
		{
			int temp = mid / i;
			if (temp > n)
				temp = n;

			sum += temp;
		}

		if (sum < k)
		{
			start = mid + 1;
			continue;
		}

		end = mid - 1;
	}

	cout << start;

	return 0;
}