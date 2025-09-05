#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int startIdx = 0, endIdx = 1, result = 0;
	cin >> n;

	vector<int> inputNum(n);

	for (int i = 0; i < n; i++)
	{
		cin >> inputNum[i];
	}

	sort(inputNum.begin(), inputNum.end());

	for (int i = 0; i < n; i++)
	{
		int findNum = inputNum[i];
		
		startIdx = 0;
		endIdx = n - 1;

		while (startIdx < endIdx)
		{
			int temp = inputNum[startIdx] + inputNum[endIdx];
			//cout << "¿¬»ê : " << temp;
			if (temp == findNum)
			{
				if (startIdx == i)
				{
					startIdx++;
					continue;
				}

				if (endIdx == i)
				{
					endIdx--;
					continue;
				}

				result++;
				break;
			}
				
			if (temp < findNum)
			{
				startIdx++;
				continue;
			}

			endIdx--;
		}
	}

	cout << result;

	return 0;
}