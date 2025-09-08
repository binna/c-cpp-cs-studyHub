#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	queue<int> q;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}

	while (q.size() > 1)
	{
		q.pop();

		int num = q.front();
		q.push(num);
		q.pop();
	}

	cout << q.front();
	return 0;
}