#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, m, left, right, sum, result = 0;

	cin >> n >> m;

	vector<long long> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	left = 0;
	right = 0;
	sum = list[0];

	while (left < n)
	{
		if (sum == m)
			result++;

		if (sum > m)
		{
			sum -= list[left];
			left++;
			continue;
		}

		right++;

		if (right == n)
			break;

		sum += list[right];

	}

	cout << result;

	return 0;
}