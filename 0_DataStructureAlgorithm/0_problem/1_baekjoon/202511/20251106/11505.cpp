#include <iostream>
#include <vector>

using namespace std;

static const int MOD = 1000000007;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k, leafNodeSize = 1, totalNodeSize, startIdx, a, b;
	long long c, multiValue;
	cin >> n >> m >> k;

	while (leafNodeSize <= n)
	{
		leafNodeSize <<= 1;
	}

	totalNodeSize = leafNodeSize * 2;
	startIdx = totalNodeSize - leafNodeSize;

	vector<long long> binaryTree(totalNodeSize, 1);

	for (int i = startIdx; i < startIdx + n; i++)
	{
		cin >> binaryTree[i];
	}

	for (int i = startIdx - 1; i > 0; i--)
	{
		auto leftIdx = 2 * i;
		binaryTree[i] = (binaryTree[leftIdx] * binaryTree[leftIdx + 1]) % MOD;
	}

	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;

		switch (a)
		{
		case 1:
			b = startIdx + b - 1;
			binaryTree[b] = c;

			while ((b /= 2) > 0)
			{
				binaryTree[b] = (binaryTree[b * 2] * binaryTree[b * 2 + 1]) % MOD;
			}
			break;
		case 2:
			multiValue = 1;

			b = startIdx + b - 1;
			c = startIdx + c - 1;

			while (b <= c)
			{
				if (b % 2 == 1)
					multiValue = (multiValue * binaryTree[b]) % MOD;

				if (c % 2 == 0)
					multiValue = (multiValue * binaryTree[c]) % MOD;

				b = (b + 1) / 2;
				c = (c - 1) / 2;
			}
			cout << multiValue << '\n';
			break;
		}
	}

	return 0;
}