#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map<string, string> m;

	m.insert(make_pair("c=", ""));
	m.insert(make_pair("c-", ""));
	m.insert(make_pair("dz=", ""));
	m.insert(make_pair("d-", ""));
	m.insert(make_pair("lj", ""));
	m.insert(make_pair("nj", ""));
	m.insert(make_pair("s=", ""));
	m.insert(make_pair("z=", ""));

	int maxSize = 3, result = 0, notMatchCnt = 0;

	string word;
	cin >> word;

	for (int start = 0; start < word.size(); start++)
	{
		string temp = "";
		notMatchCnt++;

		for (int end = 0; end < maxSize && start + end < word.size(); end++)
		{
			temp += word[start + end];

			if (m.find(temp) != m.end())
			{
				if (notMatchCnt - 1 > 0)
					result += notMatchCnt - 1;

				result++;
				notMatchCnt = 0;
				start += end;
			}
		}
	}

	if (notMatchCnt > 0)
		result += notMatchCnt;

	cout << result;

	return 0;
}