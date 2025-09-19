#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int n;
int cost[16][16];
int dp[1 << 16][16];

int Tsp(int mask, int i);

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	// 0번에서 출발, mask=1<<0
	cout << Tsp(1, 0) << '\n';

	return 0;
}

// 상태 정의
//		mask : 방문 집합
//		i : 현재 도시
//		저장값 : 남은 도시 다 돌고 0으로 돌아가는 최소 비용
int Tsp(int mask, int i)
{
	// 종료 조건
	//		모든 도시 방문했으면 출발점 0으로 복귀
	//		복귀길이 없으면 INT_MAX로 리턴
	if (mask == (1 << n) - 1)
	{
		if (cost[i][0] == 0)
			return INT_MAX;

		return cost[i][0];
	}

	// 메모제이션
	//		이미 계산한 적이 있으면 그대로 반환
	int& result = dp[mask][i];
	if (result != -1) 
		return result;

	result = INT_MAX;

	// 전이식
	//		아직 방문 안 한 도시 j로 이동
	// 비용 갱신
	//		result = min(result, Tsp(mask | (1 << j), j) + cost[i][j]);
	for (int j = 0; j < n; j++) 
	{
		if ((mask & (1 << j)) == 0 && cost[i][j] != 0) 
		{
			int next = Tsp(mask | (1 << j), j);
			if (next != INT_MAX)
				result = min(result, next + cost[i][j]);
		}
	}
	return result;
}