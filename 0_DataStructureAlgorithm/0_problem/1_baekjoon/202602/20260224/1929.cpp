#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;

	vector<bool> list(n + 1, true);

	list[0] = false;
	list[1] = false;

	for (int i = 2; i <= n; i++)
	{
		for (int j = i + i; j <= n; j = j + i)
			list[j] = false;
	}

	for (int i = m; i <= n; i++)
	{
		if (list[i])
			cout << i << "\n";
	}
	
	return 0;
}