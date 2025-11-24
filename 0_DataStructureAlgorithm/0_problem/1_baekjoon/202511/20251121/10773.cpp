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
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			s.pop();
			continue;
		}
		s.push(temp);
	}

	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}