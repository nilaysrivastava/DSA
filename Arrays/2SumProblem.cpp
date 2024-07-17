// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_map;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];

            if (num_map.find(complement) != num_map.end())
            {
                result.push_back(num_map[complement]);
                result.push_back(i);
                return result;
            }

            num_map[nums[i]] = i;
        }

        return result;
    }
};

int main()
{
    // Example input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Create an instance of Solution and find the indices of the two numbers
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    // Print the result
    if (!result.empty())
    {
        cout << "Indices of the two numbers are: " << result[0] << " and " << result[1] << endl;
    }
    else
    {
        cout << "No two sum solution found" << endl;
    }

    return 0;
}
