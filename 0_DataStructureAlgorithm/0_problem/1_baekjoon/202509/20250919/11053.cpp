#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> sequence(n);
	vector<int> dp(n, 1);
	 
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		cout << sequence[i] << "===========================" << endl;
		for (int j = i - 1; j >= 0; j--)
		{
			cout << " >> " << j << endl;

			if (sequence[j] < sequence[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << "===========================" << endl;
	for (int i = 1; i < n; i++)
	{
		cout << dp[i] << endl;
	}
	
	cout << *max_element(dp.begin(), dp.end());


	return 0;
}