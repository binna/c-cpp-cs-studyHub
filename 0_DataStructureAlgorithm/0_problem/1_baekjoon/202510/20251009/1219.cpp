#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef struct Edge
{
	int start;
	int end;
	int price;
};

int main(void)
{
	int n, sCity, eCity, m;
	cin >> n >> sCity >> eCity >> m;

	vector<Edge> edgeList;
	vector<long> dist(n, LONG_MIN);
	vector<long> cityMoney(n);

	for (int i = 0; i < m; i++)
	{
		int s, e, p;
		cin >> s >> e >> p;

		edgeList.push_back({ s, e, p });
	}

	for (int i = 0; i < n; i++)
	{
		cin >> cityMoney[i];
	}

	dist[sCity] = cityMoney[sCity];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			auto edge = edgeList[j];

			if (dist[edge.start] != LONG_MIN
				&& dist[edge.end] < dist[edge.start] + cityMoney[edge.end] - edge.price)
			{
				dist[edge.end] = dist[edge.start] + cityMoney[edge.end] - edge.price;
			}
		}
	}

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < m; j++)
		{
			auto edge = edgeList[j];

			if (dist[edge.start] == LONG_MIN)
				continue;

			if (dist[edge.start] == LONG_MAX)
			{
				dist[edge.end] = LONG_MAX;
				continue;
			}

			if (dist[edge.end] < dist[edge.start] + cityMoney[edge.end] - edge.price)
			{
				dist[edge.end] = LONG_MAX;
			}
		}
	}

	if (dist[eCity] == LONG_MIN)
		cout << "gg\n";
	else if (dist[eCity] == LONG_MAX)
		cout << "Gee\n";
	else
		cout << dist[eCity] << '\n';

	return 0;
}