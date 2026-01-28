#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include<iostream>

using namespace std;

const int DISCOUNT_PERIOD = 10;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    int answer = 0;
    int buyLen = 0;

    int wantLen = want.size();
    int discountLen = discount.size();

    unordered_map<string, int> need;
    unordered_map<string, int> have;

    for (int i = 0; i < wantLen; i++)
    {
        need[want[i]] = number[i];
    }

    // ÃÊ±â 10ÀÏ
    for (int i = 0; i < DISCOUNT_PERIOD; i++)
    {
        if (need[discount[i]] != 0)
        {
            have[discount[i]]++;

            if (have[discount[i]] == need[discount[i]])
                buyLen++;
        }
    }

    if (buyLen == wantLen) 
        answer++;

    for (int i = 0; i < discountLen - DISCOUNT_PERIOD; i++)
    {
        if (need[discount[i]] != 0)
        {
            have[discount[i]]--;

            if (have[discount[i]] == (need[discount[i]] - 1))
            {
                buyLen--;
            }
        }

        if (need[discount[i + DISCOUNT_PERIOD]] != 0)
        {
            have[discount[i + DISCOUNT_PERIOD]]++;

            if (have[discount[i + DISCOUNT_PERIOD]] == need[discount[i + DISCOUNT_PERIOD]])
            {
                buyLen++;
            }
        }

        if (buyLen == wantLen) 
            answer++;
    }

    return answer;
}

int main()
{
    auto temp = solution(
        { "banana", "apple", "rice", "pork", "pot" },
        { 3, 2, 2, 2, 1 },
        { 
            "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", 
            "pot", "banana", "apple", "banana" });

    cout << temp;

    return 0;
}