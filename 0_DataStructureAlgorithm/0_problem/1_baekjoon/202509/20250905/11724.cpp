#include<iostream>
#include<vector>
#include<stack>
using namespace std;

static vector<bool> visited;
static vector<vector<int>> adj;

static stack<int> temp;

int main()
{
	int n, m, count = 0;
	cin >> n >> m;

	visited = vector<bool>(n + 1, false);
	adj.resize(n + 1);

	int vetex = 0;

	for (auto i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (visited[i]) continue;
		temp.push(i);

		while (!temp.empty())
		{
			int num = temp.top();
			temp.pop();

			if (!visited[num])
				visited[num] = true;

			for (auto j = 0; j < adj[num].size(); j++)
			{
				if (visited[adj[num][j]]) continue;
				temp.push(adj[num][j]);
			}
		}

		count++;
	}

	cout << count;

	return 0;
}