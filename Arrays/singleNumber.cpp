// Given a non-empty array of integers nums, every element appears
// twice except for one. Find that single one.

// You must implement a solution with a linear runtime
// complexity and use only constant extra space.

// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 3:

// Input: nums = [1]
// Output: 1

// Constraints:

// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xorr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};

int main()
{
    // Example input
    vector<int> nums = {4, 1, 2, 1, 2};

    // Create an instance of Solution and find the single number
    Solution solution;
    int result = solution.singleNumber(nums);

    // Print the result
    cout << "The single number is: " << result << endl;

    return 0;
}
