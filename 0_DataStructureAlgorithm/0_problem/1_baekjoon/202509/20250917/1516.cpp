#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int n, now;
	cin >> n;

	vector<vector<int>> adjList(n + 1);
	
	vector<int> time(n + 1);
	vector<int> inDegree(n + 1);
	vector<int> answer(n + 1);

	queue<int> q;
	stack<int> s;

	for (int i = 1; i <= n; i++)
	{
		int n1;
		cin >> n1;

		while (true)
		{
			int n2;
			cin >> n2;

			if (n2 == -1) break;

			adjList[n2].push_back(i);
			inDegree[i]++;
		}

		time[i] = n1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		for (auto next : adjList[now])
		{
			answer[next] = max(answer[next], answer[now] + time[now]);
			inDegree[next]--;

			if (inDegree[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		cout << answer[i] + time[i] << " ";
	}

	return 0;
}