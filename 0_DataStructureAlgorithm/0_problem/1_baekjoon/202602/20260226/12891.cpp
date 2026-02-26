//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//static int minCnt[4];
//static char dnaText[4] = { 'A', 'C' , 'G' ,'T' };
//static int dnaCnt[4] = { 0, };
//
//int GetDnaIdx(char c)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		if (c == dnaText[i])
//			return i;
//	}
//	return -1;
//}
//
//int CheckCondition()
//{
//	int result = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		if (minCnt[i] <= dnaCnt[i])
//			result++;
//	}
//	return result;
//}
//
//int main(void)
//{
//	int s, p, result = 0;
//	string password;
//
//	cin >> s >> p >> password;
//
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> minCnt[i];
//	}
//
//	if (password.size() >= p)
//	{
//		for (int i = 0; i < p; i++)
//		{
//			int idx = GetDnaIdx(password[i]);
//			if (idx != -1)
//				dnaCnt[idx]++;
//		}
//
//		if (CheckCondition() == 4)
//			result++;
//
//		for (int i = p; i < password.size(); i++)
//		{
//			int idx = GetDnaIdx(password[i - p]);
//			if (idx != -1)
//				dnaCnt[idx]--;
//
//			idx = GetDnaIdx(password[i]);
//			if (idx != -1)
//				dnaCnt[idx]++;
//			
//			if (CheckCondition() == 4)
//				result++;
//		}
//	}
//
//	cout << result;
//
//	return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

static int myAnswer[4] = {0,};
static int checkAnswer[4] = {0,};
static int checkMatch = 0;

void Add(char c)
{
	switch (c)
	{
	case 'A':
		myAnswer[0]++;
		if (checkAnswer[0] == myAnswer[0])
			checkMatch++;
		return;
	case 'C':
		myAnswer[1]++;
		if (checkAnswer[1] == myAnswer[1])
			checkMatch++;
		return;
	case 'G':
		myAnswer[2]++;
		if (checkAnswer[2] == myAnswer[2])
			checkMatch++;
		return;
	case 'T':
		myAnswer[3]++;
		if (checkAnswer[3] == myAnswer[3])
			checkMatch++;
		return;
	}
}

void Remove(char c)
{
	switch (c)
	{
	case 'A':
		if (checkAnswer[0] == myAnswer[0])
			checkMatch--;
		myAnswer[0]--;
		return;
	case 'C':
		if (checkAnswer[1] == myAnswer[1])
			checkMatch--;
		myAnswer[1]--;
		return;
	case 'G':
		if (checkAnswer[2] == myAnswer[2])
			checkMatch--;
		myAnswer[2]--;
		return;
	case 'T':
		if (checkAnswer[3] == myAnswer[3])
			checkMatch--;
		myAnswer[3]--;
		return;
	}
}

int main(void)
{
	int s, p, result = 0;
	string password;

	cin >> s >> p >> password;

	for (int i = 0; i < 4; i++)
	{
		cin >> checkAnswer[i];

		if (checkAnswer[i] == 0)
			checkMatch++;
	}

	if (password.size() >= p)
	{
		for (int i = 0; i < p; i++)
			Add(password[i]);

		if (checkMatch == 4)
			result++;

		int passwordSize = password.size();

		for (int i = p; i < passwordSize; i++)
		{
			Remove(password[i - p]);
			Add(password[i]);

			if (checkMatch == 4)
				result++;
		}
	}

	cout << result;

	return 0;
}