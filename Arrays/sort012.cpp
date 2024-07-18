// Given an array nums with n objects colored red, white, or blue,
// sort them in-place so that objects of the same color are adjacent,
// with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

#include <iostream>
#include <vector>

class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    // Create a sample vector with unsorted colors (0, 1, 2)
    std::vector<int> colors = {2, 0, 1, 2, 1, 0};

    // Print the unsorted colors
    std::cout << "Unsorted Colors: ";
    for (int color : colors)
    {
        std::cout << color << " ";
    }
    std::cout << std::endl;

    // Call the sortColors function to sort the vector
    Solution().sortColors(colors);

    // Print the sorted colors
    std::cout << "Sorted Colors: ";
    for (int color : colors)
    {
        std::cout << color << " ";
    }
    std::cout << std::endl;

    return 0;
}
