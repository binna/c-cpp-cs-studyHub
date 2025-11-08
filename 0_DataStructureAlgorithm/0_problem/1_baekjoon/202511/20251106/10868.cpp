#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, leafNodeSize = 1, totalNodeSize, startIdx, a, b, min;
	cin >> n >> m;

	while (leafNodeSize < n)
	{
		leafNodeSize <<= 1;
	}

	totalNodeSize = leafNodeSize * 2;
	startIdx = totalNodeSize - leafNodeSize;

	vector<int> binaryTree(totalNodeSize, INT_MAX);

	for (int i = startIdx; i < startIdx + n; i++)
	{
		cin >> binaryTree[i];
	}

	for (int i = startIdx - 1; i > 0; i--)
	{
		auto leftIdx = 2 * i;
		binaryTree[i] = (binaryTree[leftIdx] < binaryTree[leftIdx + 1]) ?
			binaryTree[leftIdx] : binaryTree[leftIdx + 1];
	}

	for (int i = 0; i < m; i++)
	{
		min = INT_MAX;

		cin >> a >> b;

		a = startIdx + a - 1;
		b = startIdx + b - 1;

		while (a <= b)
		{
			if (a % 2 == 1)
			{
				if (min > binaryTree[a])
					min = binaryTree[a];
			}

			if (b % 2 == 0)
			{
				if (min > binaryTree[b])
					min = binaryTree[b];
			}

			a = (a + 1) / 2;
			b = (b - 1) / 2;
		}
		cout << min << '\n';
	}

	return 0;
}