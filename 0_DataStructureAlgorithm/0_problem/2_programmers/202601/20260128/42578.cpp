#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 0;

    map<string, int> table;

    for (auto clothe : clothes)
    {
        table[clothe[1]]++;
    }

    for (auto cnt : table)
    {
        answer *= (cnt.second + 1);
    }

    return answer - 1;
}

int main(void)
{
    solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });
    return 0;
}