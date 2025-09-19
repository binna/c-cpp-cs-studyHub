#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dpTable1(n + 1);
	vector<vector<int>> dpTable2(n + 1);

	dpTable1[1] = 0;
	dpTable2[1].push_back(1);
	dpTable2[0].push_back(1);

	for (int i = 2; i <= n; i++)
	{
		dpTable1[i] = dpTable1[i - 1] + 1;

		dpTable2[i] = dpTable2[i - 1];
		dpTable2[i].push_back(i);

		if (i % 2 == 0)
		{
			int temp = dpTable1[i / 2] + 1;
			if (dpTable1[i] > temp)
			{
				dpTable1[i] = temp;

				dpTable2[i] = dpTable2[i / 2];
				dpTable2[i].push_back(i);
			}
		}

		if (i % 3 == 0)
		{
			int temp = dpTable1[i / 3] + 1;
			if (dpTable1[i] > temp)
			{
				dpTable1[i] = temp;

				dpTable2[i] = dpTable2[i / 3];
				dpTable2[i].push_back(i);
			}
		}
	}

	cout << dpTable1[n] << '\n';

	for (int i = dpTable2[n].size() - 1; i >= 0; i--)
	{
		cout << dpTable2[n][i] << ' ';
	}

	return 0;
}