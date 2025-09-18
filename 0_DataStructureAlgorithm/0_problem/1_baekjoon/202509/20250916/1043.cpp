#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;
vector<int> truthPeople;
static vector<vector<int>> party;

void Union(int, int);
int Find(int);

int main()
{
	int n, m, t, result = 0;
	cin >> n >> m >> t;

	parent.resize(n + 1);
	party.resize(m);
	truthPeople.resize(t);

	for (int i = 0; i < t; i++)
	{
		cin >> truthPeople[i];
	}

	for (int i = 0; i < m; i++)
	{
		int pritySize;
		cin >> pritySize;

		for (int j = 0; j < pritySize; j++)
		{
			int temp;
			cin >> temp;
			party[i].push_back(temp);
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		if (party[i].size() > 1)
		{
			for (int j = 0; j < party[i].size() - 1; j++)
			{
				Union(party[i][j], party[i][j + 1]);
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		truthPeople[i] = Find(truthPeople[i]);
	}

	for (int i = 0; i < m; i++)
	{
		bool isTalk = true;
		for (int j = 0; j < party[i].size(); j++)
		{
			for (int z = 0; z < t; z++)
			{
				if (Find(party[i][j]) == truthPeople[z])
					isTalk = false;
			}
		}
		
		if (isTalk)
			result++;
	}

	cout << result;

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
	if (parent[a] == a)
		return a;

	return parent[a] = Find(parent[a]);
}