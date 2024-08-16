// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int count = 0;
        int left = 0, right = 0;
        int odd_count = 0;

        while (right < nums.size())
        {
            // Expand the window by including the right pointer
            if (nums[right] % 2 != 0)
            {
                odd_count++;
            }
            right++;

            // Shrink the window from the left until we have exactly k odd numbers
            while (odd_count > k)
            {
                if (nums[left] % 2 != 0)
                {
                    odd_count--;
                }
                left++;
            }

            // If we have exactly k odd numbers, count the subarrays
            if (odd_count == k)
            {
                int temp_left = left;
                while (temp_left < right && nums[temp_left] % 2 == 0)
                {
                    temp_left++;
                }
                count += (temp_left - left + 1);
            }
        }

        return count;
    }
};
