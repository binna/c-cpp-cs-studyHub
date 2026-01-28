#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> elements) 
{
    set<int> s;

    int arrLen = elements.size();

    for (int i = 1; i < arrLen + 1; i++)
    {
        for (int j = 0; j < arrLen * 2; j++)
        {
            int sum = 0;
            for (int z = 0; z < i; z++)
            {
                int addIdx = j + z;
                sum += elements[addIdx % arrLen];
            }
            s.insert(sum);
        }
    }

    return s.size();
}

int main(void)
{
    cout << solution({ 7,9,1,1, 4 });
}