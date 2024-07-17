// Given an array arr containing n integers and an integer k.
// Your task is to find the length of the longest Sub-Array
// with the sum of the elements equal to the given value k.

// Examples:

// Input :
// arr[] = {10, 5, 2, 7, 1, 9}, k = 15
// Output : 4
// Explanation:
// The sub-array is {5, 2, 7, 1}.

// Input :
// arr[] = {-1, 2, 3}, k = 6
// Output : 0
// Explanation:
// There is no such sub-array with sum 6.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1<=n<=105
// -105<=arr[i], K<=105

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        unordered_map<long long, int> preSum;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (sum == K)
                maxLen = max(maxLen, i + 1);
            long long rem = sum - K;
            if (preSum.find(rem) != preSum.end())
            {
                int len = i - preSum[rem];
                maxLen = max(maxLen, len);
            }
            if (preSum.find(sum) == preSum.end())
            {
                preSum[sum] = i;
            }
        }
        return maxLen;
    }
};

int main()
{
    // Example input
    int A[] = {10, 5, 2, 7, 1, 9};
    int N = sizeof(A) / sizeof(A[0]);
    int K = 15;

    // Create an instance of Solution and find the length of the longest subarray
    Solution solution;
    int result = solution.lenOfLongSubarr(A, N, K);

    // Print the result
    cout << "The length of the longest subarray is: " << result << endl;

    return 0;
}
