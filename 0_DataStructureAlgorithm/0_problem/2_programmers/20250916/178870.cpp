#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    vector<int> answer;

    int startIdx = 0, endIdx = 0, sum = 0, sequenceLen = sequence.size();

    while (startIdx < sequenceLen && endIdx <= sequenceLen)
    {

        if (sum < k)
        {
            if (endIdx == sequenceLen) break;
            sum += sequence[endIdx];
            endIdx++;
            continue;
        }

        if (sum == k)
        {
            if (answer.empty() || (endIdx - startIdx - 1) < (answer[1] - answer[0]))
                answer = { startIdx, (endIdx - 1) };
        }
           
        sum -= sequence[startIdx];
        startIdx++;
    }


    return answer;
}


int main()
{
    vector<int> a = { 1, 1, 1, 2, 3, 4, 5 };
    auto temp = solution(a, 5);

    cout << temp[0] << "/" << temp[1];
    return 0;
}
