#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, result = 0;
	cin >> n >> m;

	vector<vector<int>> adjList(n + 1, vector<int>());
	vector<bool> visted(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		adjList[s].push_back(e);
		adjList[e].push_back(s);
	}

	queue<int> q;
	q.push(1);
	visted[1] = true;

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		for (auto next : adjList[node])
		{
			if (visted[next])
				continue;

			result++;
			visted[next] = true;
			q.push(next);
		}
	}

	cout << result;

	return 0;
}