#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int n, m, k, totalSize, leafSize;
	cin >> n >> m >> k;

	//while (true)
	//{
	//	int temp = pow(2, totalSize);

	//	if (temp >= n)
	//		break;

	//	totalSize++;
	//}

	//leafSize = pow(2, totalSize);
	//totalSize = leafSize * 2;

	// double형 계산 → int 변환 과정에서 부동소수 오차가 날 수 있다고 함
	// 아래의 방식이 모든 세그먼트 트리 교재/풀이에서 이 패턴을 사용
	leafSize = 1;
	while (leafSize < n)
		leafSize <<= 1;

	totalSize = leafSize << 1;

	cout << totalSize << "," << leafSize << endl;

	vector<long long> v(totalSize, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> v[totalSize - leafSize + i];
	}

	for (int i = totalSize - leafSize - 1; i > 0; i--)
	{
		v[i] = v[2 * i] + v[2 * i + 1];
	}

	for (int i = 0; i < m + k; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		switch (a)
		{
		case 1:
			{
				int idx = totalSize - leafSize + b - 1;
				v[idx] = c;

				while ((idx /= 2) > 0)
				{
					v[idx] = v[2 * idx] + v[2 * idx + 1];
				}
			}
			break;
		case 2:
			{
				long long sum = 0;

				b = totalSize - leafSize + b - 1;
				c = totalSize - leafSize + c - 1;
				while (b <= c)
				{
					if (b % 2 == 1)
						sum += v[b];

					if (c % 2 == 0)
						sum += v[c];

					b = (b + 1) / 2;
					c = (c - 1) / 2;
				}
				cout << sum << '\n';
			}
			break;
		}
	}

	return 0;
}