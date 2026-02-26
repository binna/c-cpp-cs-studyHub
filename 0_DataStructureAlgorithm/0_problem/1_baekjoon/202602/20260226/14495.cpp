#include <iostream>

using namespace std;

static long long fibonacci[116];

int main(void)
{
	int n;
	cin >> n;

	fibonacci[0] = 1;
	fibonacci[1] = 1;
	fibonacci[2] = 1;

	for (int i = 3; i < 116; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 3];
		//cout << fibonacci[i] << endl;;
	}

	cout << fibonacci[n - 1];

	return 0;
}