#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	queue<int> card;

	for (int i = 1; i <= n; i++)
	{
		card.push(i);
	}

	while (card.size() >= 2)
	{
		int first = card.front();
		card.pop();
		cout << first << " ";

		int second = card.front();
		card.pop();
		card.push(second);
	}

	int last = card.front();
	card.pop();
	cout << last << " ";

	return 0;
}