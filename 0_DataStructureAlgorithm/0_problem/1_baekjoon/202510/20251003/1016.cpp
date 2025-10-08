#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long min, max;
	int count = 0;

	cin >> min >> max;

	vector<bool> checkFlag(max - min + 1, false);

	for (long long i = 2; i * i <= max; i++)
	{
		long long pow = i * i;
		long long start_idx = min / pow;

		//cout << pow << ", "<< start_idx << endl;

		if (min % pow != 0)
		{
			start_idx++;
		}

		for (long long j = start_idx; pow * j <= max; j++)
		{
			checkFlag[(int)((j * pow) - min)] = true;
		}
	}

	for (int i = 0; i <= max - min; i++)
	{
		if (!checkFlag[i])
			count++;
	}

	cout << count;

	return 0;
}