#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> value(k + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;

		for (int j = k; j >= w; j--)
		{
			value[j] = max(value[j], v + value[j - w]);
		}
	}

	cout << *max_element(value.begin(), value.end());

	return 0;
}