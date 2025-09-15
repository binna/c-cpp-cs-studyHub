#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		q.push(temp);
	}

	
	int result = 0;
	while (q.size() >= 2)
	{
		int n1, n2, sum;
		n1 = q.top();
		q.pop();
		n2 = q.top();
		q.pop();
		sum = n1 + n2;
		result += sum;
		q.push(sum);
	}

	cout << result;
	
	return 0;
};