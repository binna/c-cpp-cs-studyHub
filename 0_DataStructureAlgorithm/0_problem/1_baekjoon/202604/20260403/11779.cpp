#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
	int node;
	int weight;

	bool operator() (pair<Edge, vector<int>> o1, pair<Edge, vector<int>> o2)
	{
		return o1.first.weight > o2.first.weight;
	}
};

int main(void)
{
	int n, m, begin, end;
	cin >> n >> m;

	vector<vector<Edge>> adjList(n + 1, vector<Edge>());
	priority_queue<pair<Edge, vector<int>>, vector<pair<Edge, vector<int>>>, Edge> pq;
	vector<int> dist(n + 1, INT_MAX);
	vector<bool> visited(n + 1, false);
	vector<vector<int>> route(n + 1, vector<int>());

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back({ v, w });
	}

	cin >> begin >> end;

	dist[begin] = 0;

	pq.push(make_pair(Edge{ begin, 0 }, vector<int>{ begin }));

	while (!pq.empty())
	{
		auto edge = pq.top();
		pq.pop();

		//cout << "POP node=" << edge.first.node
		//	<< " weight=" << edge.first.weight
		//	<< " dist[node]=" << dist[edge.first.node] << '\n';

		if (visited[edge.first.node])
			continue;

		visited[edge.first.node] = true;

		for (auto cur : adjList[edge.first.node])
		{
			int sum = cur.weight + edge.first.weight;
			
			if (sum < dist[cur.node])
			{
				//cout << "- " << cur.node << endl;
				auto newRoute = edge.second;
				newRoute.push_back(cur.node);

				dist[cur.node] = sum;
				route[cur.node] = newRoute;

				pq.push(make_pair(Edge{ cur.node , sum }, newRoute));
			}
		}
	}

	cout << dist[end] << "\n";
	cout << route[end].size() << "\n";

	for (auto info : route[end])
	{
		cout << info << " ";
	}

	return 0;
}