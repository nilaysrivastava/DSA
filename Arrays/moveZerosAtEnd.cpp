// Given an integer array nums, move all 0's to the end of it while
// maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = -1;

        // Find the first zero element
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                j = i;
                break;
            }
        }

        // If there are no zeros, return
        if (j == -1)
            return;

        // Move non-zero elements to the left
        for (int i = j + 1; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

void printVector(const vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    Solution solution;

    vector<int> nums1 = {0, 1, 0, 3, 12};
    cout << "Original array: ";
    printVector(nums1);
    solution.moveZeroes(nums1);
    cout << "Array after moving zeroes: ";
    printVector(nums1);

    vector<int> nums2 = {0, 0, 1};
    cout << "Original array: ";
    printVector(nums2);
    solution.moveZeroes(nums2);
    cout << "Array after moving zeroes: ";
    printVector(nums2);

    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    printVector(nums3);
    solution.moveZeroes(nums3);
    cout << "Array after moving zeroes: ";
    printVector(nums3);

    return 0;
}
