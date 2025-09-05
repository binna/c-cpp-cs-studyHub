#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);

	int sum[100001] = {};

	for (int i = 1; i < n + 1; i++)
	{
		int temp;
		scanf("%d", &temp);

		sum[i] = sum[i - 1] + temp;
	}

	for (int i = 0; i < m; i++)
	{
		int start, end;
		
		scanf("%d %d", &start, &end);
		
		printf("%d", sum[end] - sum[start - 1]);
	}

	return 0;
}