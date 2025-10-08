#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

static vector<bool> primeNums;

int main(void)
{
	int n, result;
	cin >> n;

	primeNums.resize(2000001, true);

	primeNums[1] = false;
	for (int i = 2; i < sqrt(2000001); i++)
	{
		if (!primeNums[i])
			continue;

		for (int j = i + i; j < 2000001; j = i + j)
		{
			primeNums[j] = false;
		}
	}

	for (result = n; result < 2000001; result++)
	{
		if (!primeNums[result])
			continue;

		string temp = to_string(result);
		bool isPalindrome = true;

		//int len = temp.size();
		//for (int j = 0; j < len / 2; j++)
		//{
		//	if (temp[j] != temp[len - j - 1])
		//	{
		//		isPalindrome = false;
		//		break;
		//	}
		//}

		int start = 0;
		int end = temp.size() - 1;
		while (start < end)
		{
			if (temp[start] != temp[end])
			{
				isPalindrome = false;
				break;
			}

			start++;
			end--;
		}

		if (isPalindrome)
			break;
	}

	cout << result;

	return 0;
}