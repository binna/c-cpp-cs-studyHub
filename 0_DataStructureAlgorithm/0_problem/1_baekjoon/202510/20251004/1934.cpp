#include <iostream>

using namespace std;

int gcd(long a, long b);

int main(void)
{
	int a, b, n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << a * b / gcd(a, b) << '\n';
	}

	return 0;
}


int gcd(long a, long b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}