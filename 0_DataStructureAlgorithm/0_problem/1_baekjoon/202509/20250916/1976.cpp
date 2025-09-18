#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int city[201][201];
int route[1000];

void Union(int, int);
int Find(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	parent.resize(n + 1);

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> city[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> route[i];
	}

	for (int i = 1; i < n + 1; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (city[i][j] == 1)
				Union(i, j);
		}
	}

	int parentNum = Find(route[0]);
	bool isConnect = true;

	for (int i = 1; i < m; i++)
	{
		if (parentNum != Find(route[i]))
			isConnect = false;
	}

	cout << (isConnect ? "YES\n" : "NO\n");

	return 0;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		parent[b] = a;
}

int Find(int a)
{
	if (a == parent[a])
		return a;

	return parent[a] = Find(parent[a]);
}