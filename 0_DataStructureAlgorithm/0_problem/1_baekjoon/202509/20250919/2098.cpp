#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int n;
int cost[16][16];
int dp[1 << 16][16];

int Tsp(int mask, int i);

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	// 0������ ���, mask=1<<0
	cout << Tsp(1, 0) << '\n';

	return 0;
}

// ���� ����
//		mask : �湮 ����
//		i : ���� ����
//		���尪 : ���� ���� �� ���� 0���� ���ư��� �ּ� ���
int Tsp(int mask, int i)
{
	// ���� ����
	//		��� ���� �湮������ ����� 0���� ����
	//		���ͱ��� ������ INT_MAX�� ����
	if (mask == (1 << n) - 1)
	{
		if (cost[i][0] == 0)
			return INT_MAX;

		return cost[i][0];
	}

	// �޸����̼�
	//		�̹� ����� ���� ������ �״�� ��ȯ
	int& result = dp[mask][i];
	if (result != -1) 
		return result;

	result = INT_MAX;

	// ���̽�
	//		���� �湮 �� �� ���� j�� �̵�
	// ��� ����
	//		result = min(result, Tsp(mask | (1 << j), j) + cost[i][j]);
	for (int j = 0; j < n; j++) 
	{
		if ((mask & (1 << j)) == 0 && cost[i][j] != 0) 
		{
			int next = Tsp(mask | (1 << j), j);
			if (next != INT_MAX)
				result = min(result, next + cost[i][j]);
		}
	}
	return result;
}