#include <iostream>
#include <string>
using namespace std;

int n;
int primaryNums[] = { 2, 3, 5, 7 };
int oddNums[] = { 1, 3, 5, 7 ,9 };

void bfs(int primaryNum, int digit);
bool isPrimary(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (auto primaryNum : primaryNums)
	{
		bfs(primaryNum, 1);
	}

	return 0;
}

void bfs(int primaryNum, int digit)
{
	if (digit >= n)
	{
		cout << primaryNum << "\n";
		return;
	}
		
	for (auto oddNum : oddNums)
	{
		int num = stoi(to_string(primaryNum) + to_string(oddNum));

		if (!isPrimary(num))
			continue;

		bfs(num, digit + 1);
	}
}

bool isPrimary(int num)
{
	for (int i = 2; i < num / 2; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}