#include <iostream>

using namespace std;

int main(void)
{
	int n, result = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int alphabet[27] = { 0, };

		string word;
		cin >> word;

		char beforeChar = 0;
		bool isSuccess = true;

		for (int i = 0; i < word.size(); i++)
		{
			if (beforeChar == 0)
			{
				beforeChar = word[i];
			}
			else if (beforeChar != word[i])
			{
				beforeChar = word[i];
				if (alphabet[word[i] - 'a'] != 0)
				{
					isSuccess = false;
					break;
				}
			}

			alphabet[word[i] - 'a']++;
		}

		if (isSuccess)
			result++;
	}

	cout << result;

	return 0;
}