#include <iostream>
#include <string>
#include <vector>
using namespace std;

string texts;

int Sum(string expression);
vector<string> Split();

int main()
{
	int result = 0;
	bool isFirst = true;

	cin >> texts;

	for (auto text : Split())
	{
		if (isFirst)
		{
			isFirst = false;
			result += Sum(text);
		}
		else
			result -= Sum(text);
	}

	cout << result;
	return 0;
}

int Sum(string expression)
{
	string temp = "";
	int sum = 0;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '+')
		{
			sum += stoi(temp);
			temp = "";
			continue;
		}
		temp += expression[i];
	}
	sum += stoi(temp);
	return sum;
}

vector<string> Split()
{
	vector<string> expressions;
	string temp = "";

	for (int i = 0; i < texts.length(); i++)
	{
		if (texts[i] == '-')
		{
			expressions.push_back(temp);
			temp = "";
			continue;
		}
		temp += texts[i];
	}
	expressions.push_back(temp);
	return expressions;
}