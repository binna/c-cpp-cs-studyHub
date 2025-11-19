#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
	bool operator() (string o1, string o2)
	{
		if (o1.size() == o2.size())
		{
			int o1Len = 0, o2Len = 0;

			for (char c : o1)
			{
				if ('0' <= c && c <= '9')
					o1Len += c - '0';
			}

			for (auto c : o2)
			{
				if ('0' <= c && c <= '9')
					o2Len += c - '0';
			}

			if (o1Len == o2Len)
				return o1 > o2;

			return o1Len > o2Len;
		}

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

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		pq.push(word);
	}

	while (!pq.empty())
	{
		auto top = pq.top();
		pq.pop();

		cout << top << "\n";
	}

	return 0;
}