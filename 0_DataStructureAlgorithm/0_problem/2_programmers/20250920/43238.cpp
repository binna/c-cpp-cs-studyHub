#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long start, end, mid, cnt, max, answer;

    cnt = 0;
    mid = 0;
    answer = 0;

    max = *max_element(times.begin(), times.end());
    start = 1;
    end = max * n;

    while (start <= end)
    {
        cnt = 0;
        mid = (start + end) / 2;

        for (int j = 0; j < times.size(); j++)
        {
            cnt += (mid / times[j]);
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

int main()
{
    auto temp = solution(6, { 7, 10 });

    cout << temp;

    return 0;
}