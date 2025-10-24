#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<long> tree;

void setTree(int i)
{
	while (i != 1)
	{
		tree[i / 2] += tree[i];
		i--;
	}
}

void changeVal(int idx, long val)
{
	long diff = val - tree[idx];

	while (idx > 0)
	{
		tree[idx] += diff;
		idx /= 2;
	}
}

long getSum(long s, long e)
{
	long partSum = 0;

	while (s <= e)
	{
		if (s % 2 == 1)
			partSum += tree[s];

		if (e % 2 == 0)
			partSum += tree[e];

		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}

	return partSum;
}

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;

	int treeHeight = 0;
	int length = n;

	while (length != 0)
	{
		length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int leftNodeStartIdx = treeSize / 2;

	tree.resize(treeSize + 1, 0); 

	cout << treeSize << ", " << leftNodeStartIdx << endl;

	for (int i = leftNodeStartIdx; i < leftNodeStartIdx + n; i++)
	{
		cin >> tree[i];
	}

	setTree(treeSize - 1);

	for (int i = 0; i < m + k; i++)
	{
		long a, s, e;
		cin >> a >> s >> e;

		// 데이터 변경
		if (a == 1)
		{
			changeVal(leftNodeStartIdx - 1 + s, e);
			continue;
		}

		// 구간합 구하기
		s = s + leftNodeStartIdx - 1;
		e = e + leftNodeStartIdx - 1;
		cout << getSum(s, e) << '\n';
	}

	return 0;
}