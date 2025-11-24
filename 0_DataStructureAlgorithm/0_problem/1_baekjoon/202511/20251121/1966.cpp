#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int index;
	int important;
};

struct cmp
{
	bool operator() (int o1, int o2)
	{
		return o1 < o2;
	}
};

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{

		priority_queue<int, vector<int>, cmp> pq;
		queue<Node> q;

		int n, m, count = 0;
		cin >> n >> m;

		for (int j = 0; j < n; j++)
		{
			int import;
			cin >> import;

			pq.push(import);
			q.push({ j, import });
		}

		while (!pq.empty())
		{
			auto temp1 = pq.top();
			pq.pop();
			int idx = 0;

			while (!q.empty())
			{
				auto temp2 = q.front();
				q.pop();

				if (temp1 == temp2.important)
				{
					idx = temp2.index;
					count++;
					break;
				}

				q.push(temp2);
			}

			if (idx == m)
			{
				cout << count << '\n';
				break;
			}
		}
	}

	return 0;
}