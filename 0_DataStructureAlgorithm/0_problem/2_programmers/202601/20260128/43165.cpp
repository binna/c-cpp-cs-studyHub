#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SumTargetNumber(vector<int> numbers, int idx, int sum, int target, int* result)
{
    if (numbers.size() <= idx)
    {
        if (target == sum)
            *result = *(result) + 1;
        return;
    }
      
    int nextIdx = idx + 1;
    SumTargetNumber(numbers, nextIdx, sum + numbers[idx], target, result);
    SumTargetNumber(numbers, nextIdx, sum - numbers[idx], target, result);
}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;

    SumTargetNumber(numbers, 0, 0, target, &answer);

    return answer;
}



int main(void)
{

    cout << solution({ 1, 1, 1, 1, 1 }, 3);

    return 0;
}