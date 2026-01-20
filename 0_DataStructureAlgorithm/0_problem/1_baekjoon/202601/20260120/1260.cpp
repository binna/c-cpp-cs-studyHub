#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static int n, m, v;
static vector<vector<int>> edgeList;
static vector<bool> visited;

void DFS(int);
void BFS();

int main(void)
{
	cin >> n >> m >> v;

	edgeList.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		edgeList[s].push_back(e);
		edgeList[e].push_back(s);
	}

	DFS(v);

	cout << '\n';
	
	BFS();

	return 0;
}

void DFS(int node)
{
	visited[node] = true;
	cout << node << ' ';
	
	sort(edgeList[node].begin(), edgeList[node].end());

	for (auto v : edgeList[node])
	{
		if (visited[v])
			continue;

		DFS(v);
	}
}

void BFS()
{
	queue<int> q;
	visited.assign(n + 1, false);

	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		cout << node << ' ';

		sort(edgeList[node].begin(), edgeList[node].end());

		for (auto v : edgeList[node])
		{
			if (visited[v])
				continue;

			q.push(v);
			visited[v] = true;
		}
	}
}