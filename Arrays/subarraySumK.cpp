// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

#include <iostream>
#include <vector>
#include <unordered_map> // Change from map to unordered_map for better performance
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp; // Using unordered_map for better average time complexity
        int preSum = 0;
        int count = 0;

        mpp[0] = 1;
        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            int remove = preSum - k;
            if (mpp.find(remove) != mpp.end()) {
                count += mpp[remove];
            }
            mpp[preSum] += 1;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1}; // Example input
    int k = 2; // Example target sum

    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}
