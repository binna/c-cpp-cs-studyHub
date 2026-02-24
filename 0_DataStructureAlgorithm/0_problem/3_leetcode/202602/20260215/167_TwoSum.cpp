#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result(2);

        int left, right, sum;
        left = 0;
        right = nums.size() - 1;

        while (left <= right)
        {
            sum = nums[left] + nums[right];

            if (sum == target)
            {
                result[0] = left;
                result[1] = right;
                break;
            }

            if (sum < target)
            {
                left++;
                continue;
            }

            right--;
        }

        return result;
    }
};

int main(void)
{
    Solution solution;

    vector<int> v{ 3,2,4 };

    solution.twoSum(v, 6);

    return 0;
}