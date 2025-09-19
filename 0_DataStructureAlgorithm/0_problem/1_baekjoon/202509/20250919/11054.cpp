#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> sequence(n);
	vector<int> dpAsc(n, 1);
	vector<int> dpDes(n, 1);
	vector<int> plus(n);

	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (sequence[j] < sequence[i])
				dpAsc[i] = max(dpAsc[i], dpAsc[j] + 1);
		}
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sequence[i] > sequence[j])
				dpDes[i] = max(dpDes[i], dpDes[j] + 1);
		}
	}

	for (int i = 0; i < n; i++)
	{
		plus[i] = dpAsc[i] + dpDes[i] - 1;
	}

	cout << *max_element(plus.begin(), plus.end());

	return 0;
}