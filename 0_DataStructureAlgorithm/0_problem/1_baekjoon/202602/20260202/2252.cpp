#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m;

	cin >> n >> m;

	vector<vector<int>> adjList(n + 1);
	vector<int> inDegree(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		adjList[s].push_back(e);
		inDegree[e]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << " ";

		for (auto next : adjList[now])
		{
			inDegree[next]--;

			if (inDegree[next] == 0)
				q.push(next);
		}
	}

	return 0;
}