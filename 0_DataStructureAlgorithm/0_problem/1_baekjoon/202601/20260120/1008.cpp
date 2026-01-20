#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	cout << fixed << setprecision(10) << ((double)a / b) << endl;

	return 0;
}