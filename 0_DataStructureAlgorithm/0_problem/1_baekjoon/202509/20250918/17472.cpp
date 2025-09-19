#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Edge
{
	int start;
	int end;
	int weight;

	bool operator>(const Edge& other) const
	{
		return weight > other.weight;
	}
};

int moveX[] = { 0, 1, 0, -1 };
int moveY[] = { 1, 0, -1, 0 };

vector<vector<int>> map;
vector<vector<bool>> visited;

vector<int> parent;

priority_queue<Edge, vector<Edge>, greater<Edge>> edgeList;

vector<vector<pair<int, int>>> sumIslandList;
vector<pair<int, int>> islandList;

int n, m, islandCnt, result, useEdge;

void BFS(int x, int y);
int Find(int a);
void Union(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	map.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, false));
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// 섬 분리 및 섬 정보 저장
	islandCnt = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				BFS(j, i);
				islandCnt++;
				sumIslandList.push_back(islandList);
			}
		}
	}

	for (auto island : sumIslandList)
	{
		for (int i = 0; i < island.size(); i++)
		{
			int nowX = island[i].first;
			int nowY = island[i].second;

			int nowStart = map[nowY][nowX];

			for (int i = 0; i < 4; i++)
			{
				int x = moveX[i];
				int y = moveY[i];
				int weight = 0;

				while (nowX + x >= 0 && nowX + x < m && nowY + y >= 0 && nowY + y < n)
				{
					auto check = map[nowY + y][nowX + x];
					// 같은 섬이면 엣지 못만듦
					if (check == nowStart)
						break;

					// 같은 섬 아니고 바다가 아니면 다른 섬
					// 길이가 1 이상일 때 엣지로 더해야 함
					else if (check > 0)
					{
						if (weight > 1)
							edgeList.push({ nowStart, check, weight });

						break;
					}

					// 바다임
					// 다리 길이 늘리기
					weight++;
					
					// 그리고 경로 이동하기 /////////////////////////////
					if (y < 0)
						y--;
					else if (y > 0)
						y++;
					else if (x < 0)
						x--;
					else if (x > 0)
						x++;

				}
			}
		}
	}

	parent.resize(islandCnt);
	result = 0, useEdge = 0;

	for (int i = 0; i < islandCnt; i++)
	{
		parent[i] = i;
	}

	while (!edgeList.empty())
	{
		auto now = edgeList.top();
		edgeList.pop();

		if (Find(now.start) != Find(now.end))
		{
			Union(now.start, now.end);
			result += now.weight;
			useEdge++;
		}
	}

	if (useEdge == islandCnt - 2)
		cout << result << '\n';
	else
		cout << "-1\n";

	return 0;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	islandList.clear();
	
	q.push(make_pair(x, y));
	islandList.push_back(make_pair(x, y));

	visited[y][x] = true;
	map[y][x] = islandCnt;

	while (!q.empty())
	{
		auto popNode = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int targetX = popNode.first + moveX[i];
			int targetY = popNode.second + moveY[i];

			if (targetX < 0 || targetX >= m || targetY < 0 || targetY >= n)
				continue;

			if (map[targetY][targetX] == 0)
				continue;

			if (visited[targetY][targetX])
				continue;

			islandList.push_back({ targetX, targetY });
			visited[targetY][targetX] = true;
			map[targetY][targetX] = islandCnt;

			q.push(make_pair(targetX, targetY));
		}
	}
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		parent[b] = a;
	}
}

int Find(int a)
{
	if (parent[a] == a)
		return a;

	return parent[a] = Find(parent[a]);
}