#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int computerCnt, edgeCnt, result = 0;
	cin >> computerCnt >> edgeCnt;

	vector<vector<int>> edgeList(computerCnt + 1);

	for (int i = 0; i < edgeCnt; i++)
	{
		int s, e;
		cin >> s >> e;

		edgeList[s].push_back(e);
		edgeList[e].push_back(s);
	}

	for (int i = 0; i < computerCnt; i++)
	{
		int cnt = 0;

		queue<int> q;
		vector<bool> visited(computerCnt + 1, false);

		q.push(i);
		visited[i] = true;

		while (!q.empty())
		{
			int temp = q.front();
			q.pop();

			for (auto node : edgeList[temp])
			{
				if (visited[node])
					continue;

				q.push(node);
				visited[node] = true;
				cnt++;
			}
		}

		if (result < cnt)
			result = cnt;
	}

	cout << result;

	return 0;
}