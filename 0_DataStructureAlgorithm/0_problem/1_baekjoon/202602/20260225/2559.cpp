#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k, left, right, result, sum = 0;
	cin >> n >> k;

	vector<int> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	for (int i = 0; i < k; i++)
	{
		sum += list[i];
	}

	left = 0; 
	right = k - 1;
	result = sum;

	while (++right < n)
	{
		sum += list[right];

		sum -= list[left];
		left++;

		if (result < sum)
			result = sum;
	}

	cout << result;

	return 0;
}