#include<iostream>
using namespace std;

static long sum[1000001] = {};
static long index[2000] = {};

int main()
{
	int n, m;
	long long result = 0;
	
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++)
	{
		cin >> sum[i];
		sum[i] = (sum[i] + sum[i - 1]) % m;

		if (sum[i] == 0)
			result++;

		index[sum[i]]++;
	}

	for (int i = 0; i < m; i++)
	{
		result += index[i] * (index[i] - 1) / 2;
	}

	cout << result << endl;

	return 0;
}