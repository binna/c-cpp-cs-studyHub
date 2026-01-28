#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main(void)
{
	set<int> s;
	priority_queue<int> pq;

	int n, k, sum = 0, max = 0, startIdx = 0, endIdx = 0;
	cin >> n >> k;

	vector<int> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];

		if (i < k)
		{
			sum += list[i];
			endIdx = i;
			max = sum;
		}
	}

	for (endIdx += 1; endIdx < n; endIdx++)
	{
		sum += list[endIdx];
		sum -= list[startIdx];
		startIdx++;

		if (max < sum)
			max = sum;
	}

	cout << max;

	return 0;
}