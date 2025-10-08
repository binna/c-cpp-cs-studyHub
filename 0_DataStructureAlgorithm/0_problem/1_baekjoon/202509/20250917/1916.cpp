#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main()
{
	int n, m, start, end;

	cin >> n >> m;

	vector<vector<pair<int, int>>> adjList(n + 1);

	vector<int> distance(n + 1, INT_MAX);
	vector<bool> visited(n + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	for (int i = 0; i < m; i++)
	{
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		adjList[n1].push_back(make_pair(n2, n3));
	}

	cin >> start >> end;

	q.push(make_pair(0, start));
	distance[start] = 0;

	while (!q.empty())
	{
		auto temp = q.top();
		q.pop();

		if (visited[temp.second])
			continue;

		visited[temp.second] = true;

		for (auto each : adjList[temp.second])
		{
			int sum = temp.first + each.second;

			if (distance[each.first] > sum)
			{
				distance[each.first] = sum;
				q.push(make_pair(sum, each.first));
			}
		}
	}

	cout << distance[end] << endl;

	return 0;
}