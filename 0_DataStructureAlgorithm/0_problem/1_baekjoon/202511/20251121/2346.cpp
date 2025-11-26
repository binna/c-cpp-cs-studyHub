#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Node
{
	int num;
	int move;
};

int main(void)
{
	int n;
	cin >> n;

	deque<Node> dq;

	for (int i = 0; i < n; i++)
	{
		int move;
		cin >> move;

		dq.push_back({ i + 1, move });
	}

	auto data = dq.front();
	dq.pop_front();
	cout << data.num << " ";

	while (!dq.empty())
	{
		if (data.move < 0)
		{
			for (int i = 0; i > data.move + 1; i--)
			{
				auto temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
			}

			data = dq.back();
			dq.pop_back();
			cout << data.num << " ";
			continue;
		}

		for (int i = 0; i < data.move - 1; i++)
		{
			auto temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}

		data = dq.front();
		dq.pop_front();
		cout << data.num << " ";
	}


	return 0;
}