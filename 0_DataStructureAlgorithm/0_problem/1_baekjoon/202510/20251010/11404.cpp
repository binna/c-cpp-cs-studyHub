#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

struct Edge
{
	int start;
	int end;
	int price;
};

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int s, e, p;
		cin >> s >> e >> p;

		if (dist[s][e] > p)
			dist[s][e] = p;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (dist[s][k] != INT_MAX 
					&& dist[k][e] != INT_MAX 
					&& dist[s][e] > dist[s][k] + dist[k][e])
					dist[s][e] = dist[s][k] + dist[k][e];
			}
		}
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			if (dist[y][x] == INT_MAX)
			{
				cout << "0 ";
				continue;
			}
			cout << dist[y][x] << ' ';
		}

		cout << '\n';
	}
	
	return 0;
}