#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;

	vector<bool> board(n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		board[i] = temp;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int gender, state;
		cin >> gender >> state;

		switch (gender) 
		{
		case 1:
		{
			// ³²ÇÐ»ý
			int temp = state;
			while (temp <= n)
			{
				board[temp - 1] = !board[temp - 1];
				temp += state;
			}
			break;
		}
		case 2:
		{
			int start = state, end = state;
			while (start - 1 >= 0 && end - 1 < n)
			{
				if (board[start - 1] != board[end - 1])
					break;

				start--, end++;
			}

			start++, end--;

			for (int j = start - 1; j < end; j++)
			{
				board[j] = !board[j];
			}
			break;
		}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << board[i] << " ";

		if ((i + 1) % 20 == 0)
			cout << "\n";
	}

	return 0;
}