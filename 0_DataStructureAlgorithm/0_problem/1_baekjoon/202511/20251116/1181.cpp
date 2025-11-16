#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct cmp
{
	bool operator() (string o1, string o2)
	{
		if (o1.size() == o2.size())
			return o1 > o2;

		return o1.size() > o2.size();
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<string, vector<string>, cmp> pq;
	unordered_set<string> s;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		s.insert(word);
	}

	for (auto data = s.begin(); data != s.end(); data++)
	{
		pq.push(*data);
	}

	while (!pq.empty())
	{
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}