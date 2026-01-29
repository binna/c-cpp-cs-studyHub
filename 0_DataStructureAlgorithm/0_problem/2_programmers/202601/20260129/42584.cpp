#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    int size = prices.size();
    vector<int> answer(size, 0);

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            answer[i]++;

            if (prices[i] > prices[j])
                break;
        }
    }

    return answer;
}

int main(void)
{
    for (auto num : solution({ 1, 2, 3, 2, 3 }))
    {
        cout << num << endl;
    }
    return 0;
}