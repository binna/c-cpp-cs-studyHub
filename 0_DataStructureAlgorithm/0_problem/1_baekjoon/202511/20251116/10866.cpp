#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	deque<int> dq;

	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;

		if (command == "push_front")
		{
			int num;
			cin >> num;

			dq.push_front(num);
			continue;
		}

		if (command == "push_back")
		{
			int num;
			cin >> num;

			dq.push_back(num);
			continue;
		}

		if (command == "pop_front")
		{
			if (dq.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << dq.front() << '\n';
			dq.pop_front();
			continue;
		}

		if (command == "pop_back")
		{
			if (dq.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << dq.back() << '\n';
			dq.pop_back();
			continue;
		}

		if (command == "size")
		{
			cout << dq.size() << '\n';
			continue;
		}

		if (command == "empty")
		{
			cout << dq.empty() << '\n';
			continue;
		}

		if (command == "front")
		{
			if (dq.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << dq.front() << '\n';
			continue;
		}

		if (command == "back")
		{
			if (dq.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << dq.back() << '\n';
			continue;
		}
	}

	return 0;
}