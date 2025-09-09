#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adjArr;
vector<bool> visited;

queue<int> q;

void BFS(int node);
void DFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, v;
	cin >> n >> m >> v;

	adjArr.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		adjArr[n1].push_back(n2);
		adjArr[n2].push_back(n1);
	}

	for (int i = 1; i < n + 1; i++)
	{
		sort(adjArr[i].begin(), adjArr[i].end());
	}

	visited = vector<bool>(n + 1, false);
	DFS(v);
	cout << endl;

	visited = vector<bool>(n + 1, false);
	BFS(v);
	cout << endl;

	return 0;
}

void BFS(int node)
{
	q.push(node);
	visited[node] = true;

	while (!q.empty())
	{
		int popNum = q.front();
		q.pop();
		cout << popNum << ' ';

		for (auto num : adjArr[popNum])
		{
			if (visited[num])
				continue;

			visited[num] = true;
			q.push(num);
		}
	}
}

void DFS(int node)
{
	cout << node << ' ';
	visited[node] = true;

	for (auto each : adjArr[node])
	{
		if (visited[each])
			continue;

		DFS(each);
	}
}