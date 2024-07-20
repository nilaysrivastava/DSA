// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109

#include <iostream>
#include <vector>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int cnt = 0;
        int el;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                el = nums[i];
            }
            else if (nums[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == el)
            {
                cnt1++;
            }
        }
        if (cnt1 > nums.size() / 2)
        {
            return el;
        }
        return -1;
    }
};

int main()
{
    // Sample vector with a majority element (3)
    std::vector<int> numbers = {3, 2, 3, 3, 4, 3, 2, 3, 1};

    // Call the majorityElement function to find the majority element
    int majority = Solution().majorityElement(numbers);

    // Print the result
    if (majority != -1)
    {
        std::cout << "The majority element is: " << majority << std::endl;
    }
    else
    {
        std::cout << "There is no majority element in the given vector." << std::endl;
    }

    return 0;
}
