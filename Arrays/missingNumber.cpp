// Given an array nums containing n distinct numbers in the range [0, n],
// return the only number in the range that is missing from the array.

// Example 1:

// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
// 2 is the missing number in the range since it does not appear in nums.

// Example 2:

// Input: nums = [0,1]
// Output: 2
// Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2].
// 2 is the missing number in the range since it does not appear in nums.

// Example 3:

// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9].
// 8 is the missing number in the range since it does not appear in nums.

// Constraints:

// n == nums.length
// 1 <= n <= 104
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int num : nums)
        {
            actualSum += num;
        }
        return expectedSum - actualSum;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {3, 0, 1};
    cout << "Missing number in [3, 0, 1] is: " << solution.missingNumber(nums1) << endl;

    vector<int> nums2 = {0, 1};
    cout << "Missing number in [0, 1] is: " << solution.missingNumber(nums2) << endl;

    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Missing number in [9,6,4,2,3,5,7,0,1] is: " << solution.missingNumber(nums3) << endl;

    vector<int> nums4 = {0};
    cout << "Missing number in [0] is: " << solution.missingNumber(nums4) << endl;

    return 0;
}