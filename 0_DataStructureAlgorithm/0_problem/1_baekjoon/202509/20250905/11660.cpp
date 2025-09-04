#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));

	for (auto x = 1; x < n + 1; x++)
	{
		for (auto y = 1; y < n + 1; y++)
		{
			int temp;
			scanf("%d", &temp);
			sum[y][x] = sum[y - 1][x] + sum[y][x - 1] + temp - sum[y - 1][x - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		//printf("%d %d %d %d\n", sum[y2][x2], sum[y1 - 1][x2], sum[y2][x1 - 1], sum[y1 - 1][x1 - 1]);
		printf("%d\n", sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1]);
	}
	return 0;
}