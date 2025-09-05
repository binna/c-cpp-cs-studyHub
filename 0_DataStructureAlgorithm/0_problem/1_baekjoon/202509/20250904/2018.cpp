#include <iostream>
using namespace std;

int main()
{
	int n;
	int startIndex = 1, result = 0, sum = 0;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		sum += i;
		//cout << i + 1 << ":" << sum << endl;
		if (sum == n)
		{
			//cout << "<< in >>" << endl;
			result++;
			continue;
		}


		while (sum > n)
		{
			//cout << "	startIdx : " << startIndex << ":" << sum << endl;
			sum -= startIndex;
			startIndex++;

			if (sum == n)
			{
				//cout << "<< in >>" << endl;
				result++;
				continue;
			}
		}
		//cout << "	startIdx : " << startIndex << ":" << sum << endl << endl;
	}

	cout << result;

	return 0;
}