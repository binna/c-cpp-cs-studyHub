#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
	int distance;
};

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int l, x1, y1, x2, y2;

		cin >> l >> x1 >> y1 >> x2 >> y2;

		vector<vector<bool>> board(l, vector<bool>(l, false));

		queue<Node> q;
		q.push({ x1, y1, 0 });

		while (!q.empty())
		{
			auto node = q.front();
			q.pop();

			int x = node.x;
			int y = node.y;
			int distance = node.distance;

			if (x == x2 && y == y2)
			{
				cout << distance << "\n";
				break;
			}

			// (x + 2, y + 1)
			if (x + 2 < l && y + 1 < l && !board[y + 1][x + 2])
			{
				q.push({ x + 2, y + 1, distance + 1 });
				board[y + 1][x + 2] = true;
			}

			// (x + 2, y - 1)
			if (x + 2 < l && y - 1 >= 0 && !board[y - 1][x + 2])
			{
				q.push({ x + 2, y - 1, distance + 1 });
				board[y - 1][x + 2] = true;
			}

			// (x - 2, y + 1)
			if (x - 2 >= 0 && y + 1 < l && !board[y + 1][x - 2])
			{
				q.push({ x - 2, y + 1, distance + 1 });
				board[y + 1][x - 2] = true;
			}

			// (x - 2, y - 1)
			if (x - 2 >= 0 && y - 1 >= 0 && !board[y - 1][x - 2])
			{
				q.push({ x - 2, y - 1, distance + 1 });
				board[y - 1][x - 2] = true;
			}

			// (x + 1, y + 2)
			if (x + 1 < l && y + 2 < l && !board[y + 2][x + 1])
			{
				q.push({ x + 1, y + 2, distance + 1 });
				board[y + 2][x + 1] = true;
			}

			// (x + 1, y - 2)
			if (x + 1 < l && y - 2 >= 0 && !board[y - 2][x + 1])
			{
				q.push({ x + 1, y - 2, distance + 1 });
				board[y - 2][x + 1] = true;
			}

			// (x - 1, y + 2)
			if (x - 1 >= 0 && y + 2 < l && !board[y + 2][x - 1])
			{
				q.push({ x - 1, y + 2, distance + 1 });
				board[y + 2][x - 1] = true;
			}

			// (x - 1, y - 2)
			if (x - 1 >= 0 && y - 2 >= 0 && !board[y - 2][x - 1])
			{
				q.push({ x - 1, y - 2, distance + 1 });
				board[y - 2][x - 1] = true;
			}
		}
	}

	return 0;
}