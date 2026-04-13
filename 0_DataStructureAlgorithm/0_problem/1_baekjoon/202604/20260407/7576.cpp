#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
	int day;
};

int main(void)
{
	int n, m, total = 0, cnt = 0, day = 0;
	cin >> m >> n;

	vector<vector<int>> box(n, vector<int>(m));
	vector<vector<bool>> vistid(n, vector<bool>(m));
	queue<Node> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];

			if (box[i][j] == -1)
				continue;

			if (box[i][j] == 1)
			{
				q.push({ j, i, 0 });
				vistid[i][j] = true;
				continue;
			}

			total++;
		}
	}

	
	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		int x = now.x;
		int y = now.y;
		day = now.day;

		if (x + 1 < m && !vistid[y][x + 1] && box[y][x + 1] == 0)
		{
			q.push({ x + 1, y, day + 1 });
			vistid[y][x + 1] = true;
			cnt++;
		}

		if (y + 1 < n && !vistid[y + 1][x] && box[y + 1][x] == 0)
		{
			q.push({ x, y + 1, day + 1 });
			vistid[y + 1][x] = true;
			cnt++;
		}

		if (x - 1 >= 0 && !vistid[y][x - 1] && box[y][x - 1] == 0)
		{
			q.push({ x - 1, y, day + 1 });
			vistid[y][x - 1] = true;
			cnt++;
		}

		if (y - 1 >= 0 && !vistid[y - 1][x] && box[y - 1][x] == 0)
		{
			q.push({ x, y - 1, day + 1 });
			vistid[y - 1][x] = true;
			cnt++;
		}
	}

	if (cnt == total)
		cout << day << endl;
	else
		cout << -1 << "\n";

	return 0;
}