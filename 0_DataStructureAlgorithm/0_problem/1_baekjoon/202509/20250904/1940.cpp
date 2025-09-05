#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, endIdx;
	long startIdx = 0, sum = 0, result = 0;
	cin >> n >> m;

	vector<int> material(n);
	endIdx = n - 1;


	for (int i = 0; i < n; i++)
	{
		cin >> material[i];
	}

	sort(material.begin(), material.end());

	while (startIdx != endIdx)
	{
		int sum = material[startIdx] + material[endIdx];

		if (sum == m)
			result++;

		if (sum > m)
			endIdx--;
		else
			startIdx++;
	}

	cout << result;

	return 0;
}