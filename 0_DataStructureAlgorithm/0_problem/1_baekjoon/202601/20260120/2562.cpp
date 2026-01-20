#include <iostream>

using namespace std;

int main()
{
	int resultIdx = 0, resultValue, temp;
	cin >> resultValue;

	for (int i = 1; i < 9; i++)
	{
		cin >> temp;
		if (resultValue < temp)
		{
			resultIdx = i;
			resultValue = temp;
		}
	}

	cout << resultValue << '\n' << resultIdx + 1;

	return 0;
}