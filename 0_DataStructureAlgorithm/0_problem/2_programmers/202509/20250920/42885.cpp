#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    int start = 0, end = people.size() - 1;

    sort(people.begin(), people.end());

    int sum = people[start] + people[end];
    while (start <= end)
    {
        if (start == end)
            sum = people[start];

        else
        {
            sum = people[start] + people[end];

            if (sum <= limit)
                start++;
        }

        sum = 0;
        end--;
        answer++;
    }


    return answer;
}

int main()
{
    auto temp = solution({ 70, 80, 50 }, 100);

    cout << temp;

    return 0;
}