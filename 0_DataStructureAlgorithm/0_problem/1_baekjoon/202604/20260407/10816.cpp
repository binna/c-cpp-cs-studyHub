#include <map>
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	map<int, int> table;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		table[temp]++;
	}

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		cout << table[temp] << " ";
	}

	return 0;
}