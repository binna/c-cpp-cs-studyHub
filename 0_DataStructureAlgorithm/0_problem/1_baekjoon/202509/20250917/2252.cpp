#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adjList(n + 1);
	vector<int> inDegree(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		adjList[n1].push_back(n2);

		inDegree[n2]++;
	}

	queue<int> q;
	for (int i = 1; i < n + 1; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (auto next : adjList[now])
		{
			inDegree[next]--;

			if (inDegree[next] == 0)
				q.push(next);
		}
	}

	return 0;
}