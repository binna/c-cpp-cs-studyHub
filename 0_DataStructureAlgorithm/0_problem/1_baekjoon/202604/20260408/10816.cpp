#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	map<int, int> s;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		s[temp]++;
	}

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		cout << s[temp] << " ";
	}

	return 0;
}