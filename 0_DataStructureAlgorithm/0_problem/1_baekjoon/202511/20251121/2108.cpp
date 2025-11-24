#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <climits>
#include <cmath>

using namespace std;

struct Node
{
	int num;
	int cnt;
};

struct cmp
{
	bool operator() (int o1, int o2)
	{
		return o1 > o2;
	}
};

int main(void)
{
	int n;
	cin >> n;

	vector<int> v(n);
	priority_queue<int, vector<int>, cmp> pq;
	map<int, int> m;

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		m[v[i]] += 1;
	}

	sort(v.begin(), v.end());

	int maxCnt = INT_MIN;
	int cnt = 1;

	for (auto each : m)
	{
		if (each.second > maxCnt)
		{
			maxCnt = each.second;
			pq = priority_queue<int, vector<int>, cmp>();
			pq.push(each.first);
			cnt = 0;
			continue;
		}
		else if (each.second == maxCnt)
		{
			cnt++;
			pq.push(each.first);
		}
	}


	long avg = round(sum / v.size());
	cout << avg << "\n";
	cout << v[v.size() / 2] << "\n";

	if (pq.size() < 2)
		cout << pq.top() << "\n";
	else
	{
		while (!pq.empty())
		{
			pq.pop();
			break;
		}
		cout << pq.top() << "\n";
	}

	cout << v[v.size() - 1] - v[0] << "\n";


	return 0;
}