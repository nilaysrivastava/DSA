// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        // First pass to find potential candidates
        for (int i = 0; i < n; i++) {
            if (count1 == 0 && el2 != nums[i]) {
                count1 = 1;
                el1 = nums[i];
            } else if (count2 == 0 && el1 != nums[i]) {
                count2 = 1;
                el2 = nums[i];
            } else if (nums[i] == el1) {
                count1++;
            } else if (nums[i] == el2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        // Reset counts for verification
        count1 = 0;
        count2 = 0;
        
        // Second pass to verify actual counts
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) count1++;
            if (nums[i] == el2) count2++;
        }

        vector<int> ans;
        int m = (n / 3) + 1; // Majority threshold

        // Check if candidates appear more than n/3 times
        if (count1 >= m) ans.push_back(el1);
        if (count2 >= m) ans.push_back(el2);

        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {3, 2, 3, 1, 1, 2, 2};
    
    // Find majority elements
    vector<int> result = solution.majorityElement(nums);
    
    // Print the results
    cout << "Majority elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
