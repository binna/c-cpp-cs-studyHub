#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
	int num;
	int weight;
	bool status;
};

struct cmp
{
	bool operator() (Edge o1, Edge o2)
	{
		return o1.weight > o2.weight;
	}
};

int main(void)
{
	int n, m, result = 0;
	cin >> n >> m;

	vector<vector<Edge>> adjList(n + 1);

	for (int i = 0; i < m; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;

		adjList[s].push_back({ e, w * 2 });
		adjList[e].push_back({ s, w * 2 });
	}

	queue<pair<int, int>> q;

	vector<bool> visited(n + 1, false);
	vector<int> foxDistance(n + 1, INT_MAX);
	vector<vector<int>> wolfDistance(n + 1, vector<int>(2, INT_MAX));

	priority_queue<Edge, vector<Edge>, cmp> pq;

	pq.push({ 1, 0 });
	foxDistance[1] = 0;

	while (!pq.empty())
	{
		auto edge = pq.top();
		pq.pop();

		if (visited[edge.num])
			continue;

		visited[edge.num] = true;

		for (auto cur : adjList[edge.num])
		{
			int sum = foxDistance[edge.num] + cur.weight;

			if (sum < foxDistance[cur.num])
			{
				foxDistance[cur.num] = sum;
				pq.push({ cur.num, sum });
			}
		}
	}

	pq.push({ 1, 0, true });
	wolfDistance[1][0] = 0;

	while (!pq.empty())
	{
		auto edge = pq.top();
		pq.pop();

		// 최단 거리면 그 거리로부터 다음 노드를 탐색한다
		if (edge.weight != wolfDistance[edge.num][edge.status ? 0 : 1])
			continue;

		for (auto cur : adjList[edge.num])
		{
			int sum;

			if (edge.status)
				sum = wolfDistance[edge.num][0] + (cur.weight / 2);
			else
				sum = wolfDistance[edge.num][1] + (cur.weight * 2);

			int nextIdx = (!edge.status) ? 0 : 1;

			if (sum < wolfDistance[cur.num][nextIdx])
			{
				wolfDistance[cur.num][nextIdx] = sum;
				pq.push({ cur.num, sum, !edge.status });
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (foxDistance[i] < min(wolfDistance[i][0], wolfDistance[i][1]))
			result++;
	}

	cout << result;

	return 0;
}