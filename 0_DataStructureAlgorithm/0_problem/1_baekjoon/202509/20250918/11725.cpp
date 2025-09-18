#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> adjList;

static vector<bool> visited;
static vector<int> parent;

void DeleteNode(int num);

int main()
{
	int n;
	cin >> n;

	adjList.resize(n + 1);
	parent.resize(n + 1);

	visited.assign(n + 1, false);

	for (int i = 0; i < n - 1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		
		adjList[n1].push_back(n2);
		adjList[n2].push_back(n1);
	}

	DeleteNode(1);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}


void DeleteNode(int num)
{
	visited[num] = true;

	for (auto node : adjList[num])
	{
		if (visited[node]) continue;

		parent[node] = num;
		DeleteNode(node);
	}

}