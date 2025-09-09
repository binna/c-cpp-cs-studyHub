#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string texts;
	cin >> texts;

	vector<int> num(texts.size());

	for (int i = 0; i < texts.size(); i++)
	{
		//num[i] = texts[i] - '0';
		num[i] = stoi(texts.substr(i, 1));
	}

	sort(num.rbegin(), num.rend());

	for (int i = 0; i < texts.size(); i++)
	{
		cout << num[i];
	}
	
	return 0;
}