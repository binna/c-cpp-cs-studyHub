#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long n, m, left, right, sum, result = 0;

	cin >> n >> m;

	vector<int> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	left = 0;
	right = 0;
	sum = list[0];

	while (left < n)
	{
		if (sum > m)
		{
			sum -= list[left];
			left++;
			continue;
		}

		if (sum == m)
			result++;

		right++;

		if (right >= n)
			break;

		sum += list[right];
	}

	cout << result;

	return 0;
}