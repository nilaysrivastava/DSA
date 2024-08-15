// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6

// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        long long p1 = nums[0];
        long long p2 = nums[0];
        long long maxp = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            long long current = nums[i];
            long long temp1 = max({current, p1 * current, p2 * current});
            long long temp2 = min({current, p1 * current, p2 * current});

            if (temp1 > INT_MAX || temp1 < INT_MIN || temp2 > INT_MAX || temp2 < INT_MIN)
            {
                p1 = current;
                p2 = current;
            }
            else
            {
                p1 = temp1;
                p2 = temp2;
            }

            maxp = max(maxp, p1);
        }

        return (int)maxp;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Maximum product of subarray in nums1: " << solution.maxProduct(nums1) << endl; // Output: 6

    vector<int> nums2 = {-2, 0, -1};
    cout << "Maximum product of subarray in nums2: " << solution.maxProduct(nums2) << endl; // Output: 0

    vector<int> nums3 = {-2, 3, -4};
    cout << "Maximum product of subarray in nums3: " << solution.maxProduct(nums3) << endl; // Output: 24

    return 0;
}
