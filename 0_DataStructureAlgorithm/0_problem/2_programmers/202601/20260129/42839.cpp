#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

static set<int> nums;

bool isPrime(int num)
{
    if (num < 2) 
        return false;

    if (num == 2)
        return true;

    if (num % 2 == 0) 
        return false;

    for (long long i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0) 
            return false;
    }

    return true;
}

void DFS(string curNum, string numbers, vector<bool>& used)
{
    if (curNum.empty())
        return;

    nums.insert(stoi(curNum));

    int size = numbers.size();

    for (int i = 0; i < size; i++)
    {
        if (used[i]) continue;

        used[i] = true;

        DFS(curNum + numbers[i], numbers, used);

        used[i] = false;
    }
}

int solution(string numbers) 
{
    int answer = 0;

    int numSize = numbers.size();
    for (int i = 0; i < numSize; i++)
    {
        vector<bool> used(numSize, false);
        used[i] = true;
        string curNum(1, numbers[i]);
        DFS(curNum, numbers, used);
    }

    for (auto num : nums)
    {
        if (isPrime(num))
            answer++;
    }

    return answer;
}

int main(void)
{
    //cout << "==" << solution("17") << endl;
    cout << "==" << solution("011") << endl;
    //solution("011");
    return 0;
}