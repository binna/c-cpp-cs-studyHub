#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int max = nums.size() / 2;

    set<int> list;

    for (auto num : nums)
    {
        list.insert(num);
    }


    answer = list.size();

    if (answer > max)
        answer = max;

    return answer;
}

int main(void)
{
    cout << solution({ 3,1,2,3 });
    cout << solution({ 3,3,3,2,2,4 });
    cout << solution({ 3,3,3,2,2,2 });
    return 0;
}