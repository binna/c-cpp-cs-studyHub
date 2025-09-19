#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dpTable(n + 1);

	dpTable[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		dpTable[i] = dpTable[i - 1] + 1;
		
		if (i % 2 == 0)
		{
			dpTable[i] = min(dpTable[i], dpTable[i / 2] + 1);
		}

		if (i % 3 == 0)
		{
			dpTable[i] = min(dpTable[i], dpTable[i / 3] + 1);
		}
	}

	cout << dpTable[n];

	return 0;
}