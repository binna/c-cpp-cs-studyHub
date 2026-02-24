#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result(2);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    result[0] = i;
                    result[1] = j;

                    return result;
                }
            }
        }

        return result;
    }
};

int main(void)
{
    Solution solution;

    vector<int> v{ 2, 7, 11, 15 };

    solution.twoSum(v, 9);

    return 0;
}