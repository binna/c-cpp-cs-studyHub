#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int m;
vector<int> sortNum;

int isFindNum(int findNum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m;

	sortNum.resize(m);

	for (int i = 0; i < m; i++)
	{
		cin >> sortNum[i];
	}

	sort(sortNum.begin(), sortNum.end());

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		cout << isFindNum(temp) << '\n';
	}

	return 0;
}

int isFindNum(int findNum)
{
	int startIdx = 0;
	int endIdx = sortNum.size() - 1;

	while (startIdx <= endIdx)
	{
		int midIdx = startIdx + ((endIdx - startIdx) / 2);
		
		if (sortNum[midIdx] == findNum)
			return 1;

		if (sortNum[midIdx] < findNum)
		{
			startIdx = midIdx + 1;
			continue;
		}

		endIdx = midIdx - 1;
	}

	return 0;
}