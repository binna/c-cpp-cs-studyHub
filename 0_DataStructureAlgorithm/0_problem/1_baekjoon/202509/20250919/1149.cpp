#include <iostream>
#include <vector>

using namespace std;

struct RGB
{
	int red;
	int green;
	int blue;
};

int main()
{
	int n;
	cin >> n;

	vector<RGB> house(n);

	for (int i = 0; i < n; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;

		house[i] = { r, g, b };
	}

	for (int i = 0; i < n - 1; i++)
	{
		house[i + 1].red += min(house[i].green, house[i].blue);
		house[i + 1].green += min(house[i].red, house[i].blue);
		house[i + 1].blue += min(house[i].red, house[i].green);
	}

	cout << min(min(house[n - 1].red, house[n - 1].green), house[n - 1].blue);

	return 0;
}