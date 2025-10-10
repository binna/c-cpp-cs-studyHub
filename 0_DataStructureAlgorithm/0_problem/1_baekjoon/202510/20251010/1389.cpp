#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// bfs
// 층 단위로 검색하기 때문에, 최단 거리 보장됨
static vector<vector<int>> adjList;
static vector<int> dist;

int n, m, idx, minCost;

void BFS(int node);

int main(void)
{
	cin >> n >> m;

	idx = -1, minCost = INT_MAX;
	adjList.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		BFS(i);
	}

	cout << idx;

	return 0;
}

void BFS(int node)
{
	queue<int> q;
	dist.assign(n + 1, -1);

	q.push(node);
	dist[node] = 0;

	int cost = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (auto next : adjList[cur])
		{
			if (dist[next] != -1)
				continue;

			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}

	for (int j = 1; j <= n; j++)
	{
		cost += dist[j];
	}

	if (minCost > cost)
	{
		minCost = cost;
		idx = node;
	}
}

// 플로이드 워셜
//int main(void)
//{
//	int n, m, minValue, idx;
//	cin >> n >> m;
//
//	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
//
//	for (int i = 1; i <= n; i++)
//	{
//		dist[i][i] = 0;
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		
//		dist[a][b] = 1;
//		dist[b][a] = 1;
//	}
//
//	for (int k = 1; k <= n; k++)
//	{
//		for (int s = 1; s <= n; s++)
//		{
//			for (int e = 1; e <= n; e++)
//			{
//				if (dist[s][k] != INT_MAX
//					&& dist[k][e] != INT_MAX
//					&& dist[s][e] > dist[s][k] + dist[k][e])
//				{
//					dist[s][e] = dist[s][k] + dist[k][e];
//				}
//			}
//		}
//	}
//
//	idx = 1;
//	minValue = 0;
//	for (int j = 1; j <= n; j++)
//	{
//		minValue += dist[idx][j];
//	}
//
//	for (int i = 2; i <= n; i++)
//	{
//		int temp = 0;
//		for (int j = 1; j <= n; j++)
//		{
//			if (dist[i][j] == INT_MAX)
//				continue;
//
//			temp += dist[i][j];
//		}
//
//		if (minValue > temp)
//		{
//			minValue = temp;
//			idx = i;
//		}
//	}
//
//	cout << idx;
//
//	return 0;
//}