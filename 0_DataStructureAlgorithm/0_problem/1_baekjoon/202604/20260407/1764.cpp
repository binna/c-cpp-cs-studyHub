#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	set<string> notHearTable;
	set<string> result;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		notHearTable.insert(temp);
	}

	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;

		if (notHearTable.find(temp) == notHearTable.end())
			continue;

		result.insert(temp);
	}

	cout << result.size() << "\n";

	for (auto name : result)
	{
		cout << name << "\n";
	}

	return 0;
}