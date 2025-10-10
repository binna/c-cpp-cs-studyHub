#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef struct Edge
{
	int start;
	int end;
	int weight;
};

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<Edge> edgeList;
	vector<long> distance(n + 1, LONG_MAX);

	bool isCycle = false;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edgeList.push_back({ a, b, c });
	}

	// 벨만-포드 알고리즘 수행
	distance[1] = 0;

	for (int i = 1; i < n ; i++)
	{
		for (int j = 0; j < m; j++)
		{
			auto edge = edgeList[j];
			if (distance[edge.start] != LONG_MAX
				&& distance[edge.end] > distance[edge.start] + edge.weight)
			{
				distance[edge.end] = distance[edge.start] + edge.weight;
			}
		}
	}

	// 음수 사이클 확인
	for (int i = 0; i < m; i++)
	{
		auto edge = edgeList[i];
		if (distance[edge.start] != LONG_MAX
			&& distance[edge.end] > distance[edge.start] + edge.weight)
		{
			isCycle = true;
		}
	}

	if (isCycle)
	{
		cout << -1;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (distance[i] == LONG_MAX)
			{
				cout << -1 << '\n';
				continue;
			}

			cout << distance[i] << '\n';
		}
	}

	return 0;
}