#include <iostream>
#include <vector>
#include <queue>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n, m;
	cin >> n;

	vector<vector<int>> adjList(n + 1, vector<int>());
	vector<bool> visited(n + 1, false);
	vector<int> parentNode(n + 1, 0);
	vector<int> level(n + 1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		auto popData = q.front();
		q.pop();

		for (auto data : adjList[popData])
		{
			if (visited[data])
				continue;

			q.push(data);
			visited[popData] = true;
			parentNode[data] = popData;
			level[data] = level[popData] + 1;
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		while (level[a] != level[b])
		{
			if (level[a] < level[b])
			{
				b = parentNode[b];
				continue;
			}

			if (level[a] > level[b])
			{
				a = parentNode[a];
				continue;
			}
		}

		while (a != b)
		{
			a = parentNode[a];
			b = parentNode[b];
		}

		cout << a << '\n';
	}


	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
//static int n, m;
//static vector<vector<int>> tree;
//static vector<int> depth;
//static vector<int> parent;
//static vector<bool> visited;
//
//void BFS(int);
//int excuteLCA(int a, int b);
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> n;
//
//	tree.resize(n + 1);
//	depth.resize(n + 1);
//	parent.resize(n + 1);
//	visited.resize(n + 1);
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		int s, e;
//		cin >> s >> e;
//
//		tree[s].push_back(e);
//		tree[e].push_back(s);
//	}
//
//	BFS(1);
//
//	cin >> m;
//	
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//
//		int LCA = excuteLCA(a, b);
//		cout << LCA << "\n";
//	}
//}
//
//int excuteLCA(int a, int b)
//{
//	// depth 맞추기
//	if (depth[a] < depth[b])
//	{
//		int tmep = a;
//		a = b;
//		b = tmep;
//	}
//
//	while (depth[a] != depth[b])
//	{
//		a = parent[a];
//	}
//
//	while (a != b)
//	{
//		a = parent[a];
//		b = parent[b];
//	}
//
//	return a;
//}
//
//void BFS(int node)
//{
//	queue<int> myQueue;
//	myQueue.push(node);
//	visited[node] = true;
//	int level = 1;
//	int now_size = 1;		// 현재 depth(level) 크기
//	int count = 0;			// 현재 depth에서 내가 몇 개 노드를 처리했는지 알려주는 변수
//
//	while (!myQueue.empty())
//	{
//		int now_node = myQueue.front();
//		myQueue.pop();
//
//		for (auto next : tree[now_node])
//		{
//			if (!visited[next])
//			{
//				visited[next] = true;
//				myQueue.push(next);
//				parent[next] = now_node;	// 부모노드
//				depth[next] = level;		// 노드 깊이
//			}
//		}
//
//		count++;
//
//		if (count == now_size)
//		{
//			count = 0;
//			now_size = myQueue.size();
//			level++;
//		}
//	}
//}
//////////////////////////////////////////////////////////////////////////////////////