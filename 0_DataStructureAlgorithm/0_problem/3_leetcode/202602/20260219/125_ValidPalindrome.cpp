#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
    {
        string temp = "";

        for (auto c : s)
        {
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            {
                temp += c;
                continue;
            }

            if (c >= 'A' && c <= 'Z')
                temp += 'a' + (c - 'A');
        }

        cout << temp << "//" << temp.size() << endl;

        int size = temp.size();

        if (size != 0)
        {
            for (int i = 0; i <= size / 2; i++)
            {
                //cout << i << "/" << size - 1 - i << endl;

                if (temp[i] != temp[size - 1 - i])
                    return false;
            }
        }
        
        return true;
    }
};

int main(void)
{
    // todo
    Solution solution;

    cout << solution.isPalindrome("0P");


    
    return 0;
}