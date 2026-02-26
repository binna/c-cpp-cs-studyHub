#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	for (int i = 0; i < 100; i++)
	{
		string s;
		getline(cin, s);

		if (s.size() == 0)
			break;

		int result[4] = { 0, };


		for (auto c : s)
		{
			if (c >= 'a' && c <= 'z')
			{
				result[0]++;
				continue;
			}

			if (c >= 'A' && c <= 'Z')
			{
				result[1]++;
				continue;
			}

			if (c >= '0' && c <= '9')
			{
				result[2]++;
				continue;
			}

			if (c >= ' ')
				result[3]++;
		}

		for (auto cnt : result)
		{
			cout << cnt << " ";
		}
	}

	return 0;
}