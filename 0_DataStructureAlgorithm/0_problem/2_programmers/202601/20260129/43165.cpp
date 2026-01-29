#include <iostream>
#include <string>
#include <vector>

using namespace std;


void sumResultTargetCnt(vector<int> numbers, int idx, int sum, int target, int* result)
{
    if (idx == numbers.size())
    {
        if (sum == target)
            (*result)++;
        return;
    }

    int nextIdx = idx + 1;
    sumResultTargetCnt(numbers, nextIdx, sum + numbers[idx], target, result);
    sumResultTargetCnt(numbers, nextIdx, sum - numbers[idx], target, result);

}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    sumResultTargetCnt(numbers, 0, 0, target, &answer);
    return answer;
}

int main()
{
    cout << solution({ 1, 1, 1, 1, 1 }, 3);
    return 0;
}