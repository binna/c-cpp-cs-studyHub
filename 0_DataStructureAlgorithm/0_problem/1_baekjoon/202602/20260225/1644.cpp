#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, left, right, result, sum;
	cin >> n;

	vector<int> decimal(n + 1, true);

	decimal[0] = false;
	decimal[1] = false;

	for (int i = 2; i <= n; i++)
	{
		for (int j = i + i; j <= n; j = j + i)
		{
			decimal[j] = false;
		}
	}

	left = 2;
	right = 2;
	sum = 2;
	result = 0;

	while (left < n)
	{
		if (sum == n)
			result++;

		if (sum <= n)
		{
			for (right++; right <= n; right++)
			{
				if (decimal[right])
					break;
			}

			if (right >= n)
				break;

			sum += right;
			continue;
		}

		sum -= left;

		for (left++; left <= n; left++)
		{
			if (decimal[left])
				break;
		}
	}

	if (decimal[n])
		result++;

	cout << result;

	return 0;
}