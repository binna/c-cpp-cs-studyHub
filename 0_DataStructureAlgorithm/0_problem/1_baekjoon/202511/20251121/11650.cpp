#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
};

struct cmp
{
	bool operator() (Node o1, Node o2)
	{
		if (o1.x == o2.x)
			return o1.y > o2.y;

		return o1.x > o2.x;
	}
};

int main(void)
{
	int n;
	cin >> n;

	priority_queue<Node, vector<Node>, cmp> pq;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		pq.push({ x, y });
	}

	while (!pq.empty())
	{
		auto data = pq.top();
		pq.pop();

		cout << data.x << " " << data.y << "\n";
	}
	
	return 0;
}