#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int a, b, result = 0;
	cin >> a >> b;

	vector<bool> primeNums(b + 1, true);

	primeNums[1] = false;
	for (int i = 2; i < sqrt(b); i++)
	{
		for (int j = 2; i * j <= b; j++)
		{
			primeNums[i * j] = false;
		}
	}

	for (int i = a; i <= b; i++)
	{
		if (primeNums[i])
		{
			for (int j = i; i * j <= b; j = i * j)
			{
				result++;
			}
		}
	}

	cout << result;

	return 0;
}