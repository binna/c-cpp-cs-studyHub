#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjList;
vector<int> check;

vector<bool> visited;
queue<int> q;

void BFS(int startNode);
void DFS(int node, int deep);

int main()
{
	int n, m;
	cin >> n >> m;

	adjList.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		adjList[n1].push_back(n2);
	}

	check = vector<int>(n + 1, 0);

	for (int i = 1; i < n + 1; i++)
	{
		visited = vector<bool>(n + 1, false);
		//DFS(i, 0);
		BFS(i);
	}

	int maxVaule = *max_element(check.begin(), check.end());
	for (int i = 1; i < n + 1; i++)
	{
		if (maxVaule == check[i])
			cout << i << ' ';
	}

	return 0;
}

void BFS(int startNode)
{
	q.push(startNode);
	visited[startNode] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto temp : adjList[node])
		{
			if (visited[temp]) continue;

			q.push(temp);
			visited[temp] = true;
			check[temp]++;
		}
	}
}

void DFS(int node, int deep)
{
	if (visited[node]) return;

	if (deep != 0)
		check[node]++;

	visited[node] = true;

	for (auto temp : adjList[node])
	{
		if (visited[temp]) continue;

		DFS(temp, deep + 1);
	}
}