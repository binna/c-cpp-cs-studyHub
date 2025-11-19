#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int n, result = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		stack<char> s;

		string word;
		cin >> word;

		for (auto c : word)
		{
			if (s.empty())
			{
				s.push(c);
				continue;
			}

			auto data = s.top();
			if (data == c)
			{
				s.pop();
				continue;
			}
			s.push(c);
		}

		if (s.empty())
			result++;
	}

	cout << result;

	return 0;
}