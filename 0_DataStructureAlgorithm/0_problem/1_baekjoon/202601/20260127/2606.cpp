#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, result = 0;
	cin >> n >> m;

	vector<vector<int>> edgeList(n + 1);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		edgeList[s].push_back(e);
		edgeList[e].push_back(s);
	}

	vector<bool> visited(n + 1, false);

	queue<int> q;
	q.push(1);
	visited[1] = true;

	int cnt = 0;

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		
		for (auto cur : edgeList[node])
		{
			if (visited[cur])
				continue;

			visited[cur] = true;
			q.push(cur);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}