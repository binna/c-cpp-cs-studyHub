#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

static int N, M;
static vector<vector<int>> tree;
static vector<int> depth;
static int kMax;
static int parent[21][100001];
static vector<bool> visited;

int excuteLCA(int, int);
void BFS(int);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	tree.resize(N + 1);
	depth.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int s, e;
		cin >> s >> e;

		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	// N이 노드의 개수
	int temp = 1;
	kMax = 0;

	while (temp <= N)
	{
		temp <<= 1;
		kMax++;
	}

	BFS(1);

	// 점화식으로 부모 구성
	for (int k = 1; k <= kMax; k++)
	{
		for (int n = 1; n <= N; n++)
		{
			parent[k][n] = parent[k - 1][parent[k - 1][n]];
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		int LCA = excuteLCA(a, b);
		cout << LCA << '\n';
	}

	return 0;
}

int excuteLCA(int a, int b)
{
	if (depth[a] > depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}

	// 깊이 맞추기 => 빠르기
	for (int k = kMax; k >= 0; k--)
	{
		if (pow(2, k) <= depth[b] - depth[a])
		{
			if (depth[a] <= depth[parent[k][b]])
			{
				b = parent[k][b];
			}
		}
	}

	// 동시에 올라가면서 조상을 찾는다 빠르게
	for (int k = kMax; k >= 0 && a != b; k--)
	{
		if (parent[k][a] != parent[k][b])
		{
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	int LCA = a;
	if (a != b)
		LCA = parent[0][LCA];

	return LCA;
}

void BFS(int node)
{
	queue<int> myQueue;
	myQueue.push(node);
	visited[node] = true;
	int level = 1;
	int now_size = 1;
	int count = 0;

	while (!myQueue.empty())
	{
		int now_node = myQueue.front();
		myQueue.pop();

		for (int next : tree[now_node])
		{
			if (!visited[next])
			{
				visited[next] = true;
				myQueue.push(next);
				parent[0][next] = now_node;
				depth[next] = level;
			}
		}

		count++;

		if (count == now_size)
		{
			count = 0;
			now_size = myQueue.size();
			level++;
		}
	}
}

