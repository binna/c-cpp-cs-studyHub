#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
	int rank;
};

int main(void)
{
	int n, rank = 1;
	cin >> n;

	vector<Node> studentList(n);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		studentList[i] = { x, y, 1 };
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;

			if (studentList[i].x < studentList[j].x
				&& studentList[i].y < studentList[j].y)
			{
				studentList[i].rank++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << studentList[i].rank << " ";
	}

	return 0;
}