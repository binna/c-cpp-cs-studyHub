#include <iostream>

using namespace std;

int main(void)
{
	int n, left, len;
	string temp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		left = 0;

		for (len = 0; len < temp.size(); len++)
		{
			if (temp[len] == '(')
			{
				left++;
				continue;
			}

			left--;

			if (left < 0)
				break;
		}

		if (len < temp.size() || left != 0)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
	}

	return 0;
}