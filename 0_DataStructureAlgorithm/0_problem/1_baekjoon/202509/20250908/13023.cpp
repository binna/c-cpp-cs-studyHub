#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;

int n, m;
int result = 0;

void Dfs(int num, int deepth);

int main()
{
	cin >> n >> m;

	v.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	for (int i = 0; i < n; i++)
	{
		Dfs(i, 1);

		if (result == 1)
			break;
	}

	cout << result;
	return 0;
}

void Dfs(int num, int deepth)
{
	if (deepth == 5 || result == 1)
	{
		result = 1;
		return;
	}

	visited[num] = true;

	for (auto pop : v[num])
	{
		if (visited[pop])
			continue;

		Dfs(pop, deepth + 1);
	}

	visited[num] = false;
}