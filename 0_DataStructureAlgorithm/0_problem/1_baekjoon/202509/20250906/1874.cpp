#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	//cin >> n;
	scanf_s("%d", &n);

	vector<int> sequence(n);
	vector<char> result;
	stack<int> temp;

	int num = 1;

	for (int i = 0; i < n; i++)
	{
		//cin >> sequence[i];
		scanf_s("%d", &sequence[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (sequence[i] >= num)
		{
			while (sequence[i] >= num)
			{
				temp.push(num);
				num++;
				result.push_back('+');
			}

			temp.pop();
			result.push_back('-');
		}
		else
		{
			int popNum = temp.top();
			temp.pop();

			if (popNum > sequence[i])
			{
				//cout << "NO" << '\n';
				printf("NO");
				return 0;
			}

			result.push_back('-');
		}
	}

	int cnt = result.size();
	for (int i = 0; i < cnt; i++)
	{
		printf("%c\n", result[i]);
	}
	return 0;
}