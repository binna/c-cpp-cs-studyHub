#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> adjList;
static vector<bool> visited;
static vector<int> check;

static bool isEvenGraph;

void DFS(int node);

int main()
{
	int k, v, e;
	cin >> k;
	
	for (int i = 0; i < k; i++)
	{
		cin >> v >> e;

		adjList.assign(v + 1, {});

		visited.assign(v + 1, false);
		check.assign(v + 1, 0);

		isEvenGraph = true;
	
		for (int j = 0; j < e; j++)
		{
			int n1, n2;
			cin >> n1 >> n2;

			adjList[n1].push_back(n2);
			adjList[n2].push_back(n1);
		}

		for (int j = 1; j < v + 1; j++)
		{
			if (!isEvenGraph)
				break;

			DFS(j);
		}

		cout << (isEvenGraph ? "YES\n" : "NO\n");
	}

	return 0;
}

void DFS(int node)
{
	visited[node] = true;

	for (auto temp : adjList[node])
	{
		if (!visited[temp])
		{
			check[temp] = (check[node] + 1) % 2;
			DFS(temp);
			continue;
		}

		if (check[node] == check[temp])
			isEvenGraph = false;
	}
}