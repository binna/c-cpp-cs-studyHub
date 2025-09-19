#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

const int DISCOUNT_PERIOD = 10;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;

    for (auto command : commands)
    {
        int i = command[0];
        int j = command[1];
        int k = command[2];

        vector<int> target(array.begin() + i - 1, array.begin() + j);
        sort(target.begin(), target.end());
        answer.push_back(target[k - 1]);
        cout << target[k - 1] << endl;
    }

    return answer;
}

int main()
{
    auto temp = solution(
        { 1, 5, 2, 6, 3, 7, 4 },
        {
            {2, 5, 3},
            {4, 4, 1},
            {1, 7, 3},
        }
    );


    return 0;
}