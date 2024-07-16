// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s.
// The maximum number of consecutive 1s is 3.

// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                count++;
            else
                count = 0;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    cout << "Max consecutive ones in [1, 1, 0, 1, 1, 1] is: " << solution.findMaxConsecutiveOnes(nums1) << endl;

    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    cout << "Max consecutive ones in [1, 0, 1, 1, 0, 1] is: " << solution.findMaxConsecutiveOnes(nums2) << endl;

    vector<int> nums3 = {0, 0, 0, 0, 0};
    cout << "Max consecutive ones in [0, 0, 0, 0, 0] is: " << solution.findMaxConsecutiveOnes(nums3) << endl;

    vector<int> nums4 = {};
    cout << "Max consecutive ones in [] is: " << solution.findMaxConsecutiveOnes(nums4) << endl;

    return 0;
}
