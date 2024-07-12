// Given an array arr, return the second largest distinct element from an array.
// If the second largest element doesn't exist then return -1.

// Examples:

// Input: arr = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.

// Input: arr = [10, 10]
// Output: -1
// Explanation: The largest element of the array is 10 and the second largest element does not exist so answer is -1.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ arr.size() ≤ 105
// 1 ≤ arri ≤ 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int print2largest(int arr[], int n)
    {
        if (n < 2)
            return -1;
        int large = INT_MIN, second_large = INT_MIN;
        int i;
        for (i = 0; i < n; i++)
        {
            if (arr[i] > large)
            {
                second_large = large;
                large = arr[i];
            }
            else if (arr[i] > second_large && arr[i] != large)
            {
                second_large = arr[i];
            }
        }
        if (second_large == INT_MIN)
            return -1;
        return second_large;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}