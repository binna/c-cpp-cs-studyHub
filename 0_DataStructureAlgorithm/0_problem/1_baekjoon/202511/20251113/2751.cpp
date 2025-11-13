#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	sort(list.begin(), list.end());

	for (auto num : list)
	{
		cout << num << "\n";
	}

	return 0;
}