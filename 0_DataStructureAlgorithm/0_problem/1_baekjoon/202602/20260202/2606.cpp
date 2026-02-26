#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, result = 0;
	cin >> n >> m;

	vector<vector<int>> adjList(n + 1);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		adjList[s].push_back(e);
		adjList[e].push_back(s);
	}

	for (int i = 1; i < n + 1; i++)
	{
		vector<bool> visited(n + 1, false);

		queue<int> q;
		q.push(i);
		visited[i] = true;
		int cnt = 0;

		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			for (auto cur : adjList[node])
			{
				if (visited[cur])
					continue;

				visited[cur] = true;
				q.push(cur);
				cnt++;
			}

			if (result < cnt)
				result = cnt;
		}
	}

	cout << result << endl;

	return 0;
}