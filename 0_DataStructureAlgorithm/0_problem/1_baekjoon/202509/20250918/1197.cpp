#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int start;
	int end;
	int weight;

	bool operator>(const Edge& other) const 
	{ 
		return weight > other.weight; 
	}
};

vector<int> parent;
priority_queue<Edge, vector<Edge>, greater<Edge>> edgeList;

void Union(int a, int b);
int Find(int a);

int main()
{
	int n, e, sum = 0;
	cin >> n >> e;

	parent.resize(n + 1);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edgeList.push({ a, b, c });
	}

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < n - 1;)
	{
		auto edge = edgeList.top();
		edgeList.pop();

		if (Find(edge.start) != Find(edge.end))
		{
			i++;
			Union(edge.start, edge.end);
			sum += edge.weight;
		}
	}

	cout << sum;

	return 0;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (parent[b] != a)
	{
		parent[b] = a;
	}
}

int Find(int a)
{
	if (parent[a] == a)
		return a;

	return parent[a] = Find(parent[a]);
}
