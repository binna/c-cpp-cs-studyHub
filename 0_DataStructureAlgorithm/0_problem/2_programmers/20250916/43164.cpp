#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

static vector<string> answer;
static vector<string> path;

static unordered_map<string, vector<string>> adjList;
static unordered_map<string, unordered_map<string, int>> visited;

static int total;
static bool isDone;

void DFS(string to, int idx)
{
    if (path.size() == total + 1)
    {
        answer = path;
        isDone = true;
        return;
    }

    for (string each : adjList[to])
    {
        if (visited[to][each] == 0)
            continue;

        cout << "  >" << each << endl;

        visited[to][each]--;
        path.push_back(each);

        DFS(each, idx + 1);
        if (isDone) return;

        visited[to][each]++;
        path.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for (auto each : tickets)
    {
        adjList[each[0]].push_back(each[1]);
        visited[each[0]][each[1]]++;
    }

    cout << adjList["ICN"][0] << endl;

    for (auto each : tickets)
    {
        sort(adjList[each[0]].begin(), adjList[each[0]].end());
    }

    cout << "=======================" << endl;

    total = tickets.size();
    path.push_back("ICN");
    DFS("ICN", 1);

    return answer;
}

int main()
{
    vector<vector<string>> a =
    { 
        {"ICN", "JFK"},
        {"HND", "IAD"},
        {"JFK", "HND"},
    };

    cout << "============================" << endl;

    for (auto each : solution(a))
    {
        cout << each << endl;
    }

    return 0;
}