#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// elements_len은 배열 elements의 길이입니다.
int solution(vector<int> elements) 
{
    unordered_set<int> s;

    int arrLen = elements.size();

    for (int i = 0; i < arrLen; i++)
    {
        int temp = 0;
        for (int j = i; j < i + arrLen; j++)
        {
            temp += elements[j % arrLen];
            s.insert(temp);
        }
    }

    return s.size();
}


int main()
{
    vector<int> a;
    a.push_back(7);
    a.push_back(9);
    a.push_back(1);
    a.push_back(1);
    a.push_back(4);

    cout << solution(a);
    return 0;
}
