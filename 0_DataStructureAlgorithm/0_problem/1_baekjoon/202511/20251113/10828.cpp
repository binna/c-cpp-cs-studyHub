#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v;
	
	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;
		
		if (command == "push")
		{
			int num;
			cin >> num;
			v.push_back(num);
			continue;
		}

		if (command == "pop")
		{
			if (v.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << v[v.size() - 1] << "\n";
			v.pop_back();
			continue;
		}

		if (command == "size")
		{
			cout << v.size() << "\n";
			continue;
		}

		if (command == "empty")
		{
			cout << v.empty() << "\n";
			continue;
		}

		if (command == "top")
		{
			if (v.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << v[v.size() - 1] << "\n";
			continue;
		}
	}

	return 0;
}