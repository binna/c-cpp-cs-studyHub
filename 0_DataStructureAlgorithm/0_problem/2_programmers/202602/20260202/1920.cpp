#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n;

	cin >> n;

	set<int> table;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		table.insert(temp);
	}

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		cout << !(table.find(temp) == table.end()) << "\n";
	}

	return 0;
}