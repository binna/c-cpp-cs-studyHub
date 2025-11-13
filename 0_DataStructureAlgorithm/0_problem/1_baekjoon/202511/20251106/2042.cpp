#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m, k, a, b, leafNodeSize = 1, totalNodeSize, startIdx;
	long long sum, c;
	cin >> n >> m >> k;

	while (leafNodeSize < n)
	{
		leafNodeSize <<= 1;
	}

	totalNodeSize = leafNodeSize << 1;
	startIdx = totalNodeSize - leafNodeSize;

	vector<long long> v(totalNodeSize, 0);

	for (int i = startIdx; i < startIdx + n; i++)
	{
		cin >> v[i];
	}
	
	for (int i = startIdx - 1; i > 0; i--)
	{
		int leftNodeIdx = 2 * i;
		v[i] = v[leftNodeIdx] + v[leftNodeIdx + 1];
	}

	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			int changeIdx = startIdx + b - 1;
			v[changeIdx] = c;

			while ((changeIdx /= 2) > 0)
			{
				v[changeIdx] = v[2 * changeIdx] + v[2 * changeIdx + 1];
			}
			continue;
		}

		sum = 0;
		b = startIdx + b - 1;
		c = startIdx + c - 1;
		while (b <= c)
		{
			if (b % 2 == 1)
				sum += v[b];
			
			if (c % 2 == 0)
				sum += v[c];

			b = (b + 1) / 2;
			c = (c - 1) / 2;
		}
		cout << sum << endl;
	}

	return 0;
}