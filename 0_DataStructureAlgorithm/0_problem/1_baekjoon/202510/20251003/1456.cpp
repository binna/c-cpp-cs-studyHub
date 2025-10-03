#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<bool> primeNums;

int main()
{
	long long min, max;
	int result = 0;

	cin >> min >> max;

	primeNums.assign(10000001, true);

	// 소수 구하기
	primeNums[1] = false;
	for (int i = 2; i <= sqrt(10000001); i++)
	{
		if (primeNums[i] == false)
			continue;

		for (int j = i + i; j < 10000001; j = i + j)
		{
			primeNums[j] = false;
		}
	}

	// 거의 소수 구하기
	for (int i = 2; i < 10000001; i++)
	{
		if (primeNums[i])
		{
			long long temp = i;

			while ((double)i <= (double)max / (double)temp)
			{
				if ((double)i >= (double)min / (double)temp)
					result++;

				temp = temp * i;
			}
		}
	}

	cout << result;

	return 0;
}