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

	// �Ʒ����� ���� ������ ���� ���
	// �������� ���� ���� �ִ밪
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