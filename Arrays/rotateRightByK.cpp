// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]

// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]

// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = nums[(i + n - k) % n];
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = temp[i];
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

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    cout << "Original array: ";
    printVector(nums1);
    solution.rotate(nums1, k1);
    cout << "Rotated array by " << k1 << " steps: ";
    printVector(nums1);

    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    cout << "Original array: ";
    printVector(nums2);
    solution.rotate(nums2, k2);
    cout << "Rotated array by " << k2 << " steps: ";
    printVector(nums2);

    return 0;
}
