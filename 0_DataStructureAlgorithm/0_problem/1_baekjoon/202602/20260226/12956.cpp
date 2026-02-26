#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Node
{
	int num;
	int weight;
};

struct Edge
{
	int u;
	int v;
	int w;
};

struct cmp
{
	bool operator() (Node o1, Node o2)
	{
		return o1.weight > o2.weight;
	}
};

using namespace std;

int main(void)
{
	int n, m, result = 0;
	cin >> n >> m;

	vector<int> answerList(m, 0);

	vector<vector<int>> baseDist(n, vector<int>(n, INT_MAX));
	vector<Edge> edgeList(m);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		edgeList[i] = { u, v,w };
	}

	
	for (int nodeNum = 0; nodeNum < n; nodeNum++)
	{
		vector<vector<Node>> adjList(n, vector<Node>());
		priority_queue<Node, vector<Node>, cmp> pq;
		vector<bool> visited(n, false);

		for (int i = 0; i < m; i++)
		{
			adjList[edgeList[i].u].push_back({ edgeList[i].v, edgeList[i].w });
			adjList[edgeList[i].v].push_back({ edgeList[i].u, edgeList[i].w });
		}
		
		pq.push({ nodeNum, 0 });
		baseDist[nodeNum][nodeNum] = 0;
			
		while (!pq.empty())
		{
			auto node = pq.top();
			pq.pop();

			if (visited[node.num])
				continue;

			visited[node.num] = true;

			for (auto cur : adjList[node.num])
			{
				int sum = cur.weight + baseDist[nodeNum][node.num];

				if (sum < baseDist[nodeNum][cur.num])
				{
					baseDist[nodeNum][cur.num] = sum;
					pq.push({ cur.num, sum });
				}
			}
		}
	}

	for (int edgeNum = 0; edgeNum < m; edgeNum++)
	{
		vector<vector<Node>> adjList(n, vector<Node>());

		for (int i = 0; i < m; i++)
		{
			if (edgeNum == i)
				continue;

			adjList[edgeList[i].u].push_back({ edgeList[i].v, edgeList[i].w });
			adjList[edgeList[i].v].push_back({ edgeList[i].u, edgeList[i].w });
		}

		for (int startNode = 0; startNode < n; startNode++)
		{
			priority_queue<Node, vector<Node>, cmp> pq;
			vector<int> afterDist(n, INT_MAX);
			vector<bool> visited(n, false);

			pq.push({ startNode, 0 });
			afterDist[startNode] = 0;

			while (!pq.empty())
			{
				auto node = pq.top();
				pq.pop();

				if (visited[node.num])
					continue;

				visited[node.num] = true;

				for (auto cur : adjList[node.num])
				{
					int sum = cur.weight + afterDist[node.num];

					if (sum < afterDist[cur.num])
					{
						afterDist[cur.num] = sum;
						pq.push({ cur.num, sum });
					}
				}
			}

			for (int endNode = startNode + 1; endNode < n; endNode++) 
			{
				int base = baseDist[startNode][endNode];
				int now = afterDist[endNode];
				if (base != INT_MAX && (now == INT_MAX || now > base)) 
					answerList[edgeNum]++;
			}
		}
	}

	for (auto answer : answerList)
	{
		cout << answer << " ";
	}

	return 0;
}
