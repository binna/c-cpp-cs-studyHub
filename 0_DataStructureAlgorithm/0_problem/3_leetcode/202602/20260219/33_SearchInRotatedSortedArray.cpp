#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left, right, mid;

        left = 0;
        right = nums.size() - 1;

        while (left <= right)
        {
            mid = (left + right) / 2;

            cout << mid << " " << nums[mid] << "=========================" << endl;
            cout << nums[left] << endl;
            cout << nums[right] << endl;

            if (nums[mid] == target)
                return mid;

            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                    continue;
                }

                left = mid + 1;
                continue;
            }

            if (nums[right] <= target && target < nums[mid])
            {
                left = mid + 1;
                continue;
            }

            right = mid - 1;
        }

        return -1;
    }
};


int main(void)
{
    Solution solusion;

    vector<int> v { 5,1,3 };

    cout << solusion.search(v, 5);
        
}