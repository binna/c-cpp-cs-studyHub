#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

	for (int i = 0; i < n; i++)
	{
		dist[i][i] = 0;
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> dist[y][x];
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int e = 0; e < n; e++)
			{
				if (dist[s][k] == 1 && dist[k][e] == 1)
				{
					dist[s][e] = 1;
				}
			}
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << dist[y][x] << ' ';
		}

		cout << '\n';
	}

	return 0;
}