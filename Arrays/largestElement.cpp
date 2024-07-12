// Given an array arr, the task is to find the largest element in it.
// Examples:

// Input: arr= [1, 8, 7, 56, 90]
// Output: 90
// Explanation: The largest element of given array is 90.

// Input: arr = [5, 5, 5, 5]
// Output: 5
// Explanation: The largest element of given array is 5.

// Input: arr = [10]
// Output: 10
// Explanation: There is only one element which is the largest

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= arr.size()<= 105
// 0 <= arri <= 105
// arr may contain duplicate elements.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}