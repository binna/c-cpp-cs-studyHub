#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m, start = 0, end = 0, sum = 0, result = 0;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sum = v[0];
	while (start < n)
	{
		//cout << sum << "(" << start << "/" << end << ")" << endl;
		if (sum > m)
		{
			sum -= v[start];
			start++;
			continue;
		}
			
		if (sum == m)
			result++;

		end++;

		if (end == n)
			break;

		sum += v[end];
	}


	cout << result;

	return 0;
}