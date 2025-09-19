#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, result = 0;
	cin >> n;

	vector<vector<int>> triangle(n);
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int temp;
			cin >> temp;

			triangle[i].push_back(temp);
		}
	}

	vector<int> table2(n);

	// 아래에서 위로 누적해 정답 계산
	// 마지막에 남는 값이 최대값
	for (int i = n - 2; i >= 0; --i) 
	{
		for (int j = 0; j <= i; ++j) 
		{
			int left = triangle[i + 1][j];
			int right = triangle[i + 1][j + 1];
			triangle[i][j] += (left > right ? left : right);
		}
	}

	cout << triangle[0][0] << '\n';

	return 0;
}