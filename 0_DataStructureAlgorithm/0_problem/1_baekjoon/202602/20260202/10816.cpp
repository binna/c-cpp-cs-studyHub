#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n, m;

	cin >> n;

	map<int, int> table;

	for (int i = 0; i < n; i++)
	{ 
		int temp;
		cin >> temp;
		table[temp]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		
		if (table.find(temp) == table.end())
		{
			cout << "0 ";
			continue;
		}

		cout << table[temp] << " ";
	}

	return 0;
}