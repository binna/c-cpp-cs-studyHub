#include <iostream>
#include <vector>

using namespace std;

vector<long> Execute(long a, long b);
long GCB(long a, long b);

int main(void)
{
	long a, b, c;
	cin >> a >> b >> c;

	long tgcd = GCB(a, b);

	if (c % tgcd != 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		int mok = (int)(c / tgcd);
		auto ret = Execute(a, b);
		cout << ret[0] * mok << " " << ret[1] * mok;
	}

	return 0;
}

vector<long> Execute(long a, long b)
{
	if (b == 0)
		return { 1, 0 };

	long q = a / b;
	auto v = Execute(b, a % b);

	return { v[1], v[0] - v[1] * q };
}

long GCB(long a, long b)
{
	if (b == 0)
		return a;

	return GCB(b, a % b);
}