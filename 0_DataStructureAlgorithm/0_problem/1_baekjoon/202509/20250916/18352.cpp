#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adjList;
vector<int> visited;
queue<int> q;

void BFS(int startNode);

int main()
{
	int n, m, k, x, count = 0, deep = 0;
	cin >> n >> m >> k >> x;

	adjList.resize(n + 1);
	visited = vector<int>(n + 1, -1);

	vector<int> anwer;

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		adjList[n1].push_back(n2);
	}

	BFS(x);
	
	for (int i = 1; i < visited.size(); i++)
	{
		if (visited[i] == k)
		{
			anwer.push_back(i);
		}
	}
	
	if (anwer.size() == 0)
		cout << -1 << "\n";
	else
	{
		sort(anwer.begin(), anwer.end());

		for (auto temp : anwer)
		{
			cout << temp << '\n';
		}
	}

	return 0;
}

void BFS(int startNode)
{
	q.push(startNode);
	visited[startNode] = 0;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		for (auto node : adjList[temp])
		{
			if (visited[node] != -1)
				continue;

			q.push(node);
			visited[node] = visited[temp] + 1;
		}
	}
}
