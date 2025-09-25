#include <iostream>
#include <vector>

using namespace std;

static char result[50] = { 0, };

int i, j, n;

int main()
{
	cin >> n;

	for (i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (j = 0; j < temp.length(); j++)
		{
			if (temp[j] == result[j])
				continue;

			if (result[j] == 0)
			{
				result[j] = temp[j];
				continue;
			}

			result[j] = '?';
		}
	}

	i = 0;
	while (result[i] != 0)
	{
		cout << result[i];
		i++;
	}

	return 0;
}