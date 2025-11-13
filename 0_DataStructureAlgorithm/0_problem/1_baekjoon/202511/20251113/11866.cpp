#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int n, k, cnt = 1;
	cin >> n >> k;

	vector<int> result(n);
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}

	cout << "<";
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();

		if (cnt++ % k != 0)
		{
			q.push(temp);
			continue;
		}

		cout << temp;

		if (!q.empty())
			cout << ", ";
	}
	cout << ">";
}