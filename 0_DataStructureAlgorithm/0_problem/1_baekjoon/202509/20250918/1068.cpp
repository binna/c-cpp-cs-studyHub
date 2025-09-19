#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> adjList;

static vector<bool> visited;
static vector<bool> deleted;

static int result, n, removeNum, root;

void DeleteNode(int num);
void CountLeaf(int num);

int main()
{
	cin >> n;

	result = 0;

	adjList.resize(n);
	visited.assign(n, false);
	deleted.assign(n, false);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == -1)
		{
			root = i;
			continue;
		}
			

		adjList[temp].push_back(i);
	}

	cin >> removeNum;
	
	DeleteNode(removeNum);

	if (!deleted[root])
		CountLeaf(root);

	cout << result;

	return 0;
}


void DeleteNode(int num)
{
	deleted[num] = true;
	
	for (auto node : adjList[num])
	{
		if (deleted[node]) continue;

		DeleteNode(node);
	}
}

void CountLeaf(int num)
{
	visited[num] = true;

	int childCnt = 0;

	for (auto node : adjList[num])
	{
		if (deleted[node] || visited[node]) continue;

		childCnt++;
		CountLeaf(node);
	}

	if (childCnt == 0)
		result++;
}