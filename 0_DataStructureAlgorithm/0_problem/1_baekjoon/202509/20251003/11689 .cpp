#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	long n;

	cin >> n;

	long result = n;

	for (int p = 2; p <= sqrt(n); p++)
	{
		if (n % p == 0)
		{
			result = result - (result / p);

			while (n % p == 0)
			{
				n = n / p;
			}
		}
	}

	if (n > 1)
	{
		result = result - (result / n);
	}

	cout << result;

	return 0;
}