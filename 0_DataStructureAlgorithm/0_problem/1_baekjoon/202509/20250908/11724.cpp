#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> visitd;
vector<vector<int>> v;

stack<int> st;

void dfs(int);

int main()
{
	int n, m, result = 0;
	cin >> n >> m;

	v.resize(n + 1);
	visitd = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visitd[i])
			continue;

		dfs(i);
		result++;
	}

	

	cout << result;
	return 0;
}

void dfs(int i)
{
	if (visitd[i])
		return;

	visitd[i] = true;

	for (int j = 0; j < v[i].size(); j++)
	{
		if (visitd[v[i][j]])
			continue;

		dfs(v[i][j]);
	}
}


//// 스택 버전 /////////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
//int main()
//{
//	int n, m, result = 0;
//	cin >> n >> m;
//
//	vector<bool> visit(n + 1, false);
//	vector<vector<int>> v(n + 1, vector<int>());
//
//	stack<int> st;
//
//	for (int i = 0; i < m; i++)
//	{
//		int n1, n2;
//		cin >> n1 >> n2;
//		v[n1].push_back(n2);
//		v[n2].push_back(n1);
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (visit[i])
//			continue;
//
//		st.push(i);
//
//		while (!st.empty())
//		{
//			auto popNum = st.top();
//			st.pop();
//			visit[popNum] = true;
//
//			for (int j = 0; j < v[popNum].size(); j++)
//			{
//				if (visit[v[popNum][j]])
//					continue;
//
//				st.push(v[popNum][j]);
//			}
//		}
//		result++;
//	}
//
//	cout << result;
//	return 0;
//}