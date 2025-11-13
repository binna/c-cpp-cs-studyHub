#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int num;
			cin >> num;
			q.push(num);
			continue;
		}

		if (command == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << q.front() << "\n";
			q.pop();
			continue;
		}

		if (command == "size")
		{
			cout << q.size() << "\n";
			continue;
		}
				
		if (command == "empty")
		{
			cout << q.empty() << "\n";
			continue;
		}
				
		if (command == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << q.front() << "\n";
			continue;
		}
				
		if (command == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << q.back() << "\n";
			continue;
		}
	}

	return 0;
}