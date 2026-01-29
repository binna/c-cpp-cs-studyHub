#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer, max = nums.size() / 2;

    set<int> s;

    for (auto num : nums)
    {
        s.insert(num);
    }

    answer = (s.size() * 2) / 2;

    if (max < answer)
        answer = max;

    return answer;
}

int main(void)
{
    cout << solution({ 3,1,2,3 });
    cout << solution({ 3, 3, 3, 2, 2, 2 });
    return 0;
}