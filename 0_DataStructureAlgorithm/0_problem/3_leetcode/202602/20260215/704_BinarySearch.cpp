#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start, end, max, mid, cnt = 0;

        start = 0;
        end = nums.size() - 1;

        while (start <= end)
        {
            mid = (start + end) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
            {
                start = mid + 1;
                continue;
            }

            end = mid - 1;
        }

        return -1;
    }
};

int main(void)
{
    Solution solution;

    vector<int> v{ 2,5 };

    cout << solution.search(v, 5);
    return 0;
}