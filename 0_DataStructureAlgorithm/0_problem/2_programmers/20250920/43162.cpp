#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void DFS(int num, vector<bool>& visited, const vector<vector<int>>& adjList);

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    vector<vector<int>> adjList(n, vector<int>());

    for (int i = 0; i < computers.size(); i++)
    {
        cout << "i : " << i << endl;
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (i == j)
                continue;

            if (computers[i][j] == 1)
            {
                cout << "   j : " << j << endl;;
                adjList[i].push_back(j);
            }
        }
    }



    vector<bool> visited(n, false);


    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        DFS(i, visited, adjList);
        answer++;
    }
        

    return answer;
}

void DFS(int num, vector<bool>& visited, const vector<vector<int>>& adjList)
{
    visited[num] = true;

    for (auto node : adjList[num])
    {
        if (visited[node]) continue;

        DFS(node, visited, adjList);
    }
}

int main()
{
    auto temp = solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} });

    cout << temp;

    return 0;
}