#include <iostream>

using namespace std;

int gcb(long a, long b);

int main(void)
{
	long a, b;
	cin >> a >> b;

	long result = gcb(a, b);

	cout << result << endl << endl;

	while (result > 0)
	{
		cout << 1;
		result--;
	}

	return 0;
}

int gcb(long a, long b)
{
	if (b == 0)
		return a;

	return gcb(b, a % b);
}