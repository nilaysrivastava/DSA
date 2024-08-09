// Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N}
// is missing and one number 'B' occurs twice in array. Find these two numbers.
// Your task is to complete the function findTwoElement() which takes the array of integers
// arr and n as parameters and returns an array of integers of size 2 denoting the answer
// (The first index contains B and second index contains A)

// Examples

// Input: n = 2 arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and smallest positive missing number is 1.

// Input: n = 3 arr[] = {1, 3, 3}
// Output: 3 2
// Explanation: Repeating number is 3 and smallest positive missing number is 2.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ n

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        int xor_all = 0;

        // XOR all elements of the array
        for (int i = 0; i < n; i++)
        {
            xor_all ^= arr[i];
        }
        // XOR all elements from 1 to n
        for (int i = 1; i <= n; i++)
        {
            xor_all ^= i;
        }

        // Find the rightmost set bit
        int set_bit = xor_all & ~(xor_all - 1);

        int x = 0, y = 0;

        // Divide elements into two sets and XOR
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & set_bit)
            {
                x ^= arr[i];
            }
            else
            {
                y ^= arr[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i & set_bit)
            {
                x ^= i;
            }
            else
            {
                y ^= i;
            }
        }

        // Check which one is missing and which one is duplicated
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                return {x, y}; // x is the duplicate, y is missing
            }
        }
        return {y, x}; // y is the duplicate, x is missing
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    int n = arr.size();

    vector<int> result = sol.findTwoElement(arr, n);

    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}
