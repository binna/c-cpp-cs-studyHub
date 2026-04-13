#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
	int node;
	int weight;
};

struct cmp
{
	bool operator()(Edge o1, Edge o2)
	{
		return o1.weight > o2.weight;
	}
};

int main(void)
{
	int v, e, k;

	cin >> v >> e >> k;

	vector<vector<Edge>> adjList(v + 1, vector<Edge>());
	priority_queue<Edge, vector<Edge>, cmp> pq;
	vector<int> distance(v + 1, INT_MAX);
	vector<bool> visited(v + 1, false);

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back({ v, w });
	}
	
	distance[k] = 0;
	pq.push({ k, 0 });

	while (!pq.empty())
	{
		auto edge = pq.top();
		pq.pop();

		if (visited[edge.node])
			continue;

		visited[edge.node] = true;

		for (auto cur : adjList[edge.node])
		{
			auto sum = edge.weight + cur.weight;


			if (sum < distance[cur.node])
			{
				distance[cur.node] = sum;
				pq.push({ cur.node, sum });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (distance[i] == INT_MAX)
		{
			cout << "INF\n";
			continue;
		}

		cout << distance[i] << "\n";
	}

	return 0;
}