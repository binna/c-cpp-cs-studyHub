#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
	int node;
	int weight;

	bool operator() (Edge o1, Edge o2)
	{
		return o1.weight > o2.weight;
	}
};

static int n, e, v1, v2;
static vector<vector<Edge>> adjList;

int GetShortestWeight(int start, int end)
{
	priority_queue<Edge, vector<Edge>, Edge> pq;

	vector<bool> visited(n + 1, false);
	vector<int> dist(n + 1, INT_MAX);

	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		auto edge = pq.top();
		pq.pop();

		if (visited[edge.node])
			continue;

		visited[edge.node] = true;

		for (auto cur : adjList[edge.node])
		{
			int sum = edge.weight + cur.weight;

			if (sum < dist[cur.node])
			{
				dist[cur.node] = sum;
				pq.push({ cur.node, sum });
			}
		}
	}

	return dist[end];
}

int main(void)
{
	cin >> n >> e;

	adjList.assign(n + 1, vector<Edge>());

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back({ v, w });
		adjList[v].push_back({ u, w });
	}

	cin >> v1 >> v2;

	int path1_1 = GetShortestWeight(1, v1);
	int path1_2 = GetShortestWeight(v1, v2);
	int path1_3 = GetShortestWeight(v2, n);

	int path2_1 = GetShortestWeight(1, v2);
	int path2_2 = GetShortestWeight(v2, v1);
	int path2_3 = GetShortestWeight(v1, n);

	int route1 = INT_MAX;
	int route2 = INT_MAX;
	
	if (path1_1 != INT_MAX && path1_2 != INT_MAX && path1_3 != INT_MAX)
		route1 = path1_1 + path1_2 + path1_3;

	if (path2_1 != INT_MAX && path2_2 != INT_MAX && path2_3 != INT_MAX)
		route2 = path2_1 + path2_2 + path2_3;

	int answer = min(route1, route2);

	if (answer == INT_MAX)
		cout << -1 << "\n";
	else
		cout << answer << "\n";

	return 0;
}