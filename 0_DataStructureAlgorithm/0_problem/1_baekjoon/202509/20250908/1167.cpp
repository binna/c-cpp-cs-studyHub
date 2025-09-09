#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> adjArr;

vector<int> nodeDistance;
vector<bool> visited;

int v, result = 0;

queue<pair<int, int>> q;

void BFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> v;

	adjArr.resize(v + 1);

	for (int i = 1; i < v + 1; i++)
	{
		adjArr[i] = vector<pair<int, int>>();
	}

	for (int i = 0; i < v; i++)
	{
		int temp;
		cin >> temp;

		while (true)
		{
			int n1;
			cin >> n1;

			if (n1 == -1)
				break;

			int n2;
			cin >> n2;

			adjArr[temp].push_back(pair<int, int>(n1, n2));
		}
	}

	BFS(1);

	int maxIdx = 1, maxValue = nodeDistance[maxIdx];
	for (int i = 2; i < v + 1; i++)
	{
		if (nodeDistance[i] > maxValue)
		{
			maxIdx = i;
			maxValue = nodeDistance[i];
		}
	}

	BFS(maxIdx);

	sort(nodeDistance.rbegin(), nodeDistance.rend());

	cout << nodeDistance[0];

	return 0;
}

void BFS(int node)
{
	nodeDistance = vector<int>(v + 1, 0);
	visited = vector<bool>(v + 1, false);

	q.push(pair<int, int>(node, 0));
	visited[node] = true;

	while (!q.empty())
	{
		pair<int, int> pop = q.front();
		q.pop();

		for (auto each : adjArr[pop.first])
		{
			if (visited[each.first])
				continue;

			visited[each.first] = true;
			nodeDistance[each.first] = nodeDistance[pop.first] + each.second;
			q.push(pair<int, int>(each.first, nodeDistance[each.first]));
		}
	}
}