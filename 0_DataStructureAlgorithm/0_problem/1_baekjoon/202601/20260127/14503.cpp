#include <iostream>

using namespace std;

int main(void)
{
	int n, curMilk = 0, result = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;


		if (temp == curMilk)
		{
			curMilk++;
			result++;

			if (curMilk > 2)
				curMilk = 0;
		}
	}

	cout << result;

	return 0;
}