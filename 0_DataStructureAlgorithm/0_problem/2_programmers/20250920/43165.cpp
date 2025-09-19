#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void MakeTargetNumber(int index, int sum, int& result, const int& target, const vector<int>& numbers);

int solution(vector<int> numbers, int target) 
{
    int answer = 0;

    MakeTargetNumber(0, 0, answer, target, numbers);

    return answer;
}

void MakeTargetNumber(int index, int sum, int& result, const int& target, const vector<int>& numbers)
{
    if (index == numbers.size())
    {
        if (sum == target)
        {
            result++;
        }
        return;
    }

    int num = numbers[index];

    cout << num << "/" << sum << "/" << index << endl;
    index++;

    MakeTargetNumber(index, (sum + num), result, target, numbers);
    MakeTargetNumber(index, (sum - num), result, target, numbers);
}

int main()
{
    auto temp = solution({ 4, 1, 2, 1 }, 4);

    cout << temp;

    return 0;
}