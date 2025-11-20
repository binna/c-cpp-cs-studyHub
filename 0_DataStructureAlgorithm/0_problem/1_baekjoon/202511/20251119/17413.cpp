#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	string text;
	getline(cin, text);

	stack<char> s;
	bool inBracket = false;

	for (auto c : text)
	{
		if (c == ' ')
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << c;
			continue;
		}
		
		if (c == '<')
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << c;
			inBracket = true;
			continue;
		}
		
		if (c == '>')
		{
			cout << c;
			inBracket = false;
			continue;
		}
		
		if (inBracket)
		{
			cout << c;
			continue;
		}

		s.push(c);
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}