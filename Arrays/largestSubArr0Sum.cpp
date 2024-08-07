// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Examples:

// Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
// Output: 5
// Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.

// Input: arr[] = {2,10,4}, n = 3
// Output: 0
// Explanation: There is no subarray with 0 sum.

// Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
// Output: 5
// Explanation: The subarray is 0 -4 3 1 0.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n <= 105
// -1000 <= arr[i] <= 1000, for each valid i

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& A, int n) {
        unordered_map<int, int> mpp;
        int maxi = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (sum == 0) maxi = i + 1;
            else {
                if (mpp.find(sum) != mpp.end()) maxi = max(maxi, i - mpp[sum]);
                else mpp[sum] = i;
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> A1 = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Maximum length of subarray with sum zero (Example 1): " << sol.maxLen(A1, A1.size()) << endl;

    // Example 2
    vector<int> A2 = {1, 2, 3};
    cout << "Maximum length of subarray with sum zero (Example 2): " << sol.maxLen(A2, A2.size()) << endl;

    // Example 3
    vector<int> A3 = {1, 2, -3, 3};
    cout << "Maximum length of subarray with sum zero (Example 3): " << sol.maxLen(A3, A3.size()) << endl;

    return 0;
}
