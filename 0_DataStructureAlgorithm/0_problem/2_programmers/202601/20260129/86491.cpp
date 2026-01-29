#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    int resultSize[] = {0, 0};

    for (auto size : sizes)
    {
        int tempSize1[] = 
        { 
            resultSize[0] < size[0] ? size[0] : resultSize[0],
            resultSize[1] < size[1] ? size[1] : resultSize[1]
        };

        int tempSize2[] = 
        { 
            resultSize[0] < size[1] ? size[1] : resultSize[0],
            resultSize[1] < size[0] ? size[0] : resultSize[1]
        };

        if (tempSize1[0] * tempSize1[1] > tempSize2[0] * tempSize2[1])
        {
            resultSize[0] = tempSize2[0];
            resultSize[1] = tempSize2[1];
        }
        else
        {
            resultSize[0] = tempSize1[0];
            resultSize[1] = tempSize1[1];
        }
    }

    return resultSize[0] * resultSize[1];
}

int main(void)
{
    cout << solution({ { 60, 50 }, { 30, 70 }, { 60, 30 }, { 80, 40 } }) << endl;
    cout << solution({ { 10, 7 }, { 12, 3 }, { 8, 15 }, { 14, 7 }, { 5, 15 } });

    return 0;
}