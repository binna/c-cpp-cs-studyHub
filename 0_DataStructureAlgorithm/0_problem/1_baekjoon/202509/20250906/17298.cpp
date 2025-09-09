#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> sequence(n);
	vector<int> result(n, -1);
	stack<int> temp;

	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	temp.push(0);
	for (int i = 1; i < n; i++)
	{
		int num = sequence[i];
		int popIdx = temp.empty() == true ? -1 : temp.top();

		while (!temp.empty() && sequence[temp.top()] < num)
		{
			result[temp.top()] = num;
			temp.pop();
		}
		temp.push(i);
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}

	return 0;
}