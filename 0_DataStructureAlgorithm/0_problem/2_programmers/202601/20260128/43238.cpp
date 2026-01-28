#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) 
{
    long long start, end, mid, cnt, max, answer;

    cnt = 0;
    mid = 0;
    answer = 0;

    max = *(max_element(times.begin(), times.end()));
    start = 1;
    end = max * n;

    while (start <= end)
    {
        cnt = 0;
        mid = (start + end) / 2;

        for (auto time : times)
        {
            cnt += mid / time;
        }

        if (cnt < n)
        {
            start = mid + 1;
            continue;
        }

        answer = mid;
        end = mid - 1;
    }

    return answer;
}

int main(void)
{
    cout << solution(6, { 7, 10 });
    return 0;
}