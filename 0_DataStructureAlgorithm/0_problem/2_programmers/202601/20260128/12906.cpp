#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int curIdx = 0;
    answer.push_back(arr[curIdx]);

    for (auto num : arr)
    {
        if (answer[curIdx] != num)
        {
            curIdx++;
            answer.push_back(num);
        }
    }

    return answer;
}

int main(void)
{
    for (auto num : solution({ 1,1,3,3,0,1,1 }))
    {
        cout << num << endl;
    }
    
    return 0;
}