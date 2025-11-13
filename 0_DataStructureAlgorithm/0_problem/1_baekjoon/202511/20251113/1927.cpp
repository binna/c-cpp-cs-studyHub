#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pq;

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			if (pq.empty())
			{
				cout << "0" << "\n";
				continue;
			}

			int temp = pq.top();
			pq.pop();
			cout << temp << "\n";
			continue;
		}

		pq.push(temp);
	}

	return 0;
}