#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	set<char> s;
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');

	while (true)
	{
		string word;
		cin >> word;

		if (word == "end")
			break;

		char before = word[0], repeatCnt = 0;
		int vowelCnt = s.count(before);
		bool isPass = true;

		for (int i = 1; i < word.size(); i++)
		{
			char c = word[i];
			if (before == c && c != 'e' && c != 'o')
			{
				isPass = false;
				break;
			}

			if (s.count(before) == s.count(c))
			{
				repeatCnt++;

				if (repeatCnt >= 2)
				{
					isPass = false;
					break;
				}
			}
			else
			{
				repeatCnt = 0;
			}

			before = c;
			vowelCnt += s.count(c);
		}

		cout << "<" << word << ">";

		if (vowelCnt > 0 && isPass)
			cout << " is acceptable.\n";
		else
			cout << " is not acceptable.\n";
	}

	return 0;
}