#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;

    set<string> table;

    sort(phone_book.begin(), phone_book.end());

    for (auto phone : phone_book)
    {
        cout << phone << endl;

        string temp = "";
        for (char c : phone)
        {
            temp += c;

            if (table.find(temp) == table.end())
                continue;
            
            answer = false;
            break;
        }

        if (!answer)
            break;

        table.insert(phone);
    }

    return answer;
}

int main(void)
{
    cout << solution({ "119", "97674223", "1195524421" });
    return 0;
}