#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";

    map<string, int> table;

    for (auto person : participant)
    {
        table[person]++;
    }

    for (auto person : completion)
    {
        table[person]--;
    }

    for (auto person : table)
    {
        if (person.second > 0)
        {
            answer = person.first;
            break;
        }
    }

    return answer;
}

int main(void)
{
    cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" });
    return 0;
}