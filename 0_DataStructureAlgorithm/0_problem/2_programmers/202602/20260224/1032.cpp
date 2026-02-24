#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n;
	string result = "";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		if (result.size() == 0)
		{
			result = temp;
			continue;
		}

		if (result.size() >= temp.size())
		{
			for (int i = 0; i < temp.size(); i++)
			{
				if (result[i] != temp[i])
					result[i] = '?';
			}
			continue;
		}

		
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i] != temp[i])
				temp[i] = '?';
		}
	}

	cout << result;

	return 0;
}