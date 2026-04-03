#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
	int node;
	int weigth;

	bool operator() (Edge o1, Edge o2)
	{
		return o1.weigth > o2.weigth;
	}
};

int main(void)
{
	int v, e, k;
	
	cin >> v >> e >> k;

	vector<vector<Edge>> adjList(v + 1, vector<Edge>());
	priority_queue<Edge, vector<Edge>, Edge> pq;
	vector<int> dist(v + 1, INT_MAX);
	vector<bool> visited(v + 1, false);

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back({ v, w });
	}

	dist[k] = 0;
	pq.push({ k, 0 });

	while (!pq.empty())
	{
		auto node = pq.top();
		pq.pop();

		if (visited[node.node])
			continue;

		visited[node.node] = true;

		for (auto cur : adjList[node.node])
		{
			int sum = node.weigth + cur.weigth;

			if (sum < dist[cur.node])
			{
				dist[cur.node] = sum;
				pq.push({ cur.node, sum });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INT_MAX)
		{
			cout << "INF\n";
			continue;
		}

		cout << dist[i] << "\n";
	}


	return 0;
}