#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int targetNum = k, count = 0;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int temp = targetNum / v[i];
		if (temp > 0)
		{
			targetNum = targetNum % v[i];
			count += temp;
		}
	}

	cout << count;
	return 0;
}