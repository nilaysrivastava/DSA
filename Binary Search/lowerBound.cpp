// Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x is defined as the largest element k in arr[]
// such that k is smaller than or equal to x. Find the index of k(0-based indexing).

// Examples

// Input: n = 7, x = 0 arr[] = {1,2,8,10,11,12,19}
// Output: -1
// Explanation: No element less than 0 is found. So output is "-1".

// Your Task:
// The task is to complete the function findFloor() which returns an integer denoting the index value of K or return -1 if there isn't any such number.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ n ≤ 107
// 1 ≤ arr[i] ≤ 1018
// 0 ≤ x ≤ arr[n-1]

class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] <= x)
            {
                return i;
            }
        }
        return -1;
    }
};