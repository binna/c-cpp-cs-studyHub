#include <iostream>
#include <vector>

using namespace std;

static vector<int> v;

int Find(int a)
{
	if (a == v[a])
		return a;

	return v[a] = Find(v[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		v[b] = a;
}

bool CheckSame(int a, int b)
{
	a = Find(a);
	b = Find(b);

	return a == b;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);

	for (int i = 0; i < n + 1; i++)
	{
		v[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int command, a, b;
		cin >> command >> a >> b;

		if (command == 0)
		{
			Union(a, b);
			continue;
		}

		cout << (CheckSame(a, b) ? "YES\n" : "NO\n");
	}

	return 0;
}