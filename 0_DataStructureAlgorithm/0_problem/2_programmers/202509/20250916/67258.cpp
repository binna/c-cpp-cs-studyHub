#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <climits>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> m;

    unordered_set<string> s(gems.begin(), gems.end());

    int startIdx = 0, endIdx = 0, have = 0, need = s.size();

    cout << need;
    cout << "======================" << endl;

    for (endIdx = 0; endIdx <= gems.size(); endIdx++)
    {
        if (have < need)
        {
            if (endIdx == gems.size())
                break;

            auto temp = gems[endIdx];
            m[temp]++;

            if (m[temp] == 1)
                have++;
            continue;
        }

        while (have == need)
        {
            int curLen = endIdx - startIdx;
            int bestLen = answer.empty() ? INT_MAX : (answer[1] - answer[0] + 1);

            if (answer.size() == 0 
                || curLen < bestLen
                || (curLen == bestLen && (startIdx + 1) < answer[0]))
            {
                cout << startIdx + 1 << ", " << endIdx << endl;
                answer = { startIdx + 1, endIdx };
            }

            auto temp = gems[startIdx];
            m[temp]--;
            
            if (m[temp] == 0)
                have--;

            startIdx++;
        }
    }

    cout << have;
    cout << "======================" << endl;

    return answer;
}

int main()
{
    vector<string> a = { "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
    auto temp = solution(a);

    //cout << temp[0] << "/" << temp[1];

    return 0;
}