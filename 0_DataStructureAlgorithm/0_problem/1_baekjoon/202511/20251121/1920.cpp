#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;

	set<int> s;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		s.insert(temp);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		cout << (s.find(temp) != s.end()) << " ";
	}
	
	return 0;
}