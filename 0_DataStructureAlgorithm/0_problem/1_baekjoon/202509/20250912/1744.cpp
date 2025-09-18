#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, result = 0;
	cin >> n;

	priority_queue<int> plusPq;
	priority_queue<int, vector<int>, greater<int>> minusPq;

	int oneCnt = 0;
	int zeroCnt = 0;

	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;

		if (data > 1)
		{
			plusPq.push(data);
			continue;
		}

		if (data == 0)
		{
			zeroCnt++;
			continue;
		}

		if (data == 1)
		{
			oneCnt++;
			continue;
		}

		minusPq.push(data);
	}

	while (plusPq.size() > 1)
	{
		int n1, n2;
		n1 = plusPq.top();
		plusPq.pop();
		n2 = plusPq.top();
		plusPq.pop();

		result += (n1 * n2);
	}

	if (!plusPq.empty())
	{
		result += plusPq.top();
		plusPq.pop();
	}

	while (minusPq.size() > 1)
	{
		int n1, n2;
		n1 = minusPq.top();
		minusPq.pop();
		n2 = minusPq.top();
		minusPq.pop();

		result += (n1 * n2);
	}

	while (!minusPq.empty())
	{
		if (zeroCnt == 0) 
			result += minusPq.top();
		minusPq.pop();
	}

	cout << (result + oneCnt);
	return 0;
}