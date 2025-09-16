#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int sender[] = { 0, 0, 1, 1, 2, 2 };
static int receiver[] = { 1, 2, 0, 2, 0, 1 };

static bool visited[201][201];
static bool anwer[201];

static int bottle[3];

void BFS();

int main()
{
	cin >> bottle[0] >> bottle[1] >> bottle[2];

	BFS();

	for (int i = 0; i < 201; i++)
	{
		if (anwer[i])
			cout << i << ' ';
	}

	return 0;
}

void BFS()
{
	queue<pair<int, int>> queue;

	queue.push(make_pair(0, 0));
	visited[0][0] = true;
	anwer[bottle[2]] = true;

	while (!queue.empty())
	{
		auto temp = queue.front();
		queue.pop();

		int a = temp.first;
		int b = temp.second;
		int c = bottle[2] - a - b;

		for (int i = 0; i < 6; i++)
		{
			int next[] = { a, b, c };

			next[receiver[i]] += next[sender[i]];
			next[sender[i]] = 0;

			// 물통이 차고 넘칠 때
			// 초과하는 만큼 이전 물통에 넣고 대상 물통은 최대로 채움
			if (next[receiver[i]] > bottle[receiver[i]])
			{
				next[sender[i]] = next[receiver[i]] - bottle[receiver[i]];
				next[receiver[i]] = bottle[receiver[i]];
			}

			if (!visited[next[0]][next[1]])
			{
				visited[next[0]][next[1]] = true;
				queue.push(make_pair(next[0], next[1]));

				// A가 조건과 일치하면, 결과값에 넣어줘야 함
				if (next[0] == 0)
					anwer[next[2]] = true;
			}
		}
	}
}