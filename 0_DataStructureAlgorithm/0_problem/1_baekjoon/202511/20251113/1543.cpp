#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int checkCnt = 0, wordCnt = 0, result = 0;
	
	string text, word;
	getline(cin, text);
	getline(cin, word);

	wordCnt = word.length();

	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == word[checkCnt])
		{
			checkCnt++;
			if (checkCnt == wordCnt)
			{
				checkCnt = 0;
				result++;
			}
			continue;
		}

		if (checkCnt > 0)
		{
			i -= checkCnt;
			checkCnt = 0;
		}
	}

	cout << result;

	return 0;
}