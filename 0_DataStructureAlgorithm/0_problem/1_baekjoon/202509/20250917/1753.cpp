#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main()
{
	int v, e, k;
	cin >> v >> e >> k;

	vector<vector<pair<int, int>>> adjList(v + 1);

	vector<int> distance(v + 1, INT_MAX);
	vector<bool> visited(v + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back(make_pair(v, w));
	}

	q.push(make_pair(0, k));
	distance[k] = 0;

	while (!q.empty())
	{
		auto now = q.top();
		q.pop();

		if (visited[now.second])
			continue;

		visited[now.second] = true;

		for (auto each : adjList[now.second]) 
		{
			int sum = each.second + now.first;

			if (distance[each.first] > sum)
			{
				distance[each.first] = sum;
				q.push(make_pair(sum, each.first));
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
		cout << distance[i] << '\n';
	}

	return 0;
}