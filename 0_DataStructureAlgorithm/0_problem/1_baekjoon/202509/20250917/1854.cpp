#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> adjList(n + 1);

	vector<int> dist(n + 1, INT_MAX);
	vector<bool> visited(n + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;


	for (int i = 0; i < m; i++)
	{
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		adjList[n1].push_back(make_pair(n2, n3));
	}

	q.push(make_pair(0, 1));
	dist[1] = 0;

	while (!q.empty())
	{
		auto temp = q.top();
		q.pop();

		if (visited[temp.second]) continue;

		visited[temp.second] = true;

		for (auto each : adjList[temp.second])
		{
			int sum = each.second + temp.first;

			if (dist[each.first] > sum)
			{
				dist[each.first] = sum;
				q.push(make_pair(sum, each.first));
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INT_MAX)
		{
			cout << "-1\n";
			continue;
		}
		cout << dist[i] << '\n';
	}

	return 0;
}