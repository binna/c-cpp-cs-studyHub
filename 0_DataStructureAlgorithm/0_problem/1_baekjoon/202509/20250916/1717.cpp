#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int Find(int);
void Union(int, int);
bool CheckSame(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);

	for (int i = 1; i < n + 1; i++)
	{
		v[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int quest, a, b;
		cin >> quest >> a >> b;

		switch (quest)
		{
		case 0:
			Union(a, b);
			break;
		case 1:
			cout << (CheckSame(a, b) ? "YES\n" : "NO\n");
			break;
		}
	}

	return 0;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		v[b] = a;
	}
}

int Find(int a)
{
	if (a == v[a])
		return a;

	// 경로 압축
	// 경로 압축을 함으로써 또 Find할 때 다시 갈 필요가 없어
	return v[a] = Find(v[a]);
}

bool CheckSame(int a, int b)
{
	a = Find(a);
	b = Find(b);

	return a == b;
}