#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, k, result = 0;
	cin >> n >> k;

	vector<bool> visited(100001, false);

	if (n != k)
	{
		queue<pair<int, int>> q;
		q.push(make_pair(n, 0));
		visited[n] = true;
		bool isSuccess = false;

		while (!q.empty() && !isSuccess)
		{
			auto node = q.front();
			q.pop();

			int nextPos[] = { node.first * 2 , node.first + 1, node.first - 1 };

			for (auto next : nextPos)
			{
				if (next == k)
				{
					result = node.second + 1;
					isSuccess = true;
					break;
				}

				if (0 <= next && next <= 100000 && !visited[next])
				{
					visited[next] = true;
					q.push(make_pair(next, node.second + 1));
				}
			}
		}
	}

	cout << result;

	return 0;
}