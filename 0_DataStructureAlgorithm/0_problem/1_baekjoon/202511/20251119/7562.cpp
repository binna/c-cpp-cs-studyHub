#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
	int cnt;
};

int main(void)
{
	vector<pair<int, int>> move;
	move.push_back(make_pair(1, 2));
	move.push_back(make_pair(-1, 2));
	move.push_back(make_pair(1, -2));
	move.push_back(make_pair(-1, -2));
	move.push_back(make_pair(2, 1));
	move.push_back(make_pair(-2, 1));
	move.push_back(make_pair(2, -1));
	move.push_back(make_pair(-2, -1));

	int n, i, startX, startY, endX, endY;
	cin >> n;
	
	for (int repeat = 0; repeat < n; repeat++)
	{
		cin >> i >> startY >> startX >> endY >> endX;

		vector<vector<bool>> board(i, vector<bool>(i, false));

		queue<Node> q;
		q.push({ startX, startY, 0 });
		board[startY][startX] = true;
		bool isRun = true;

		while (!q.empty() && isRun)
		{
			auto node = q.front();
			q.pop();

			if (node.x == endX && node.y == endY)
			{
				cout << node.cnt << '\n';
				isRun = false;
				break;
			}

			for (auto next : move)
			{
				int x = node.x + next.first;
				int y = node.y + next.second;

				if (x >= 0 && x < i && y >= 0 && y < i)
				{
					if (!board[y][x])
					{
						q.push({ x, y, node.cnt + 1 });
						board[y][x] = true;
					}
				}
			}
		}
	}

	return 0;
}