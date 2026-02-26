#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, x, left, right, result = 0;

	cin >> n;

	vector<int> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	cin >> x;

	sort(list.begin(), list.end());

	left = 0;
	right = n - 1;

	while (left < right)
	{
		int sum = list[left] + list[right];

		if (sum == x)
			result++;

		if (sum < x)
		{
			left++;
			continue;
		}

		right--;
	}

	cout << result;

	return 0;
}