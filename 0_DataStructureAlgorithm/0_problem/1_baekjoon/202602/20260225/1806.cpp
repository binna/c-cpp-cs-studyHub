#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
	int n, s, left, right, sum, result;
	cin >> n >> s;

	vector<int> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	result = INT_MAX;
	left = 0;
	right = 0;
	sum = list[0];

	while (left < n)
	{
		if (sum >= s)
		{
			auto temp = right - left + 1;
			if (temp < result)
				result = temp;
		}

		if (sum <= s)
		{
			right++;

			if (right >= n)
				break;

			sum += list[right];
			continue;
		}

		sum -= list[left];
		left++;
	}

	cout << (result == INT_MAX ? 0 : result);

	return 0;
}