#include <iostream>
#include <string>

using namespace std;

static int numCnt[10] = { 0 };

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;

	long long result = a * b * c;

	for (auto word : to_string(result))
	{
		numCnt[word - '0']++;
	}

	for (auto cnt : numCnt)
	{
		cout << cnt << "\n";
	}

	return 0;
}