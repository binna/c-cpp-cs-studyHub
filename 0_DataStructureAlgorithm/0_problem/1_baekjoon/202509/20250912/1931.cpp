#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(pair<int, int> o1, pair<int, int> o2)
	{
		if (o1.second == o2.second)
		{
			return o1.first > o2.first;
		}
		return o1.second > o2.second;
	}
};

int main()
{
	int n, result;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		pq.push(pair<int, int>(start, --end));
	}

	auto target = pq.top();
	pq.pop();
	result = 1;

	while (!pq.empty())
	{
		auto temp = pq.top();
		pq.pop();

		if (temp.first > target.second) 
		{
			target = temp;
			result++;
		}
	}

	cout << result;
	return 0;
}