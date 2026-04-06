#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++)
	{


		string command;
		cin >> command;

		if (command == "push")
		{
			int num;
			cin >> num;
			s.push(num);
			continue;
		}

		if (command == "pop")
		{
			if (s.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << s.top() << "\n";
			s.pop();
			continue;
		}

		if (command == "size")
		{
			cout << s.size() << "\n";
			continue;
		}

		if (command == "empty")
		{
			cout << s.empty() << "\n";
			continue;
		}

		if (command == "top")
		{
			if (s.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << s.top() << "\n";
			continue;
		}
	}

	return 0;
}