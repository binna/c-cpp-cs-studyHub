#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct cmp
{
	bool operator()(int o1, int o2) 
	{
		int first_abs = abs(o1);
		int second_abs = abs(o2);

		if (first_abs == second_abs)
			return o1 > o2;			// 절대값이 같을 때는 음수 출력

		// 절대값을 기준으로 정렬
		return first_abs > second_abs;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp> q;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			if (q.empty())
			{
				cout <<"=" << "0\n";
				continue;
			}
			cout << "=" << q.top() << '\n';
			q.pop();
			continue;
		}

		q.push(temp);
	}

	return 0;
}