// Given an array arr[] sorted in ascending order of size N and an integer K.
// Check if K is present in the array or not.

// Example 1:

// Input:
// N = 5, K = 6
// arr[] = {1,2,3,4,6}
// Output: 1
// Exlpanation: Since, 6 is present in
// the array at index 4 (0-based indexing),
// output is 1.

// Example 2:

// Input:
// N = 5, K = 2
// arr[] = {1,3,4,5,6}
// Output: -1
// Exlpanation: Since, 2 is not present
// in the array, output is -1.

// Your Task:
// You don't need to read input or print anything. Complete the function searchInSorted()
// which takes the sorted array arr[], its size N and the element K as input parameters
// and returns 1 if K is present in the array, else it returns -1.

// Expected Time Complexity: O(Log N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 106
// 1 <= K <= 106
// 1 <= arr[i] <= 106

#include <iostream>
using namespace std;

class Solution
{
public:
    int searchInSorted(int arr[], int N, int K)
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == K)
                return 1;
        }
        return -1;
    }
};

int main()
{
    Solution solution;

    int arr1[] = {1, 2, 3, 4, 5};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    int K1 = 3;
    cout << "Array: ";
    for (int i = 0; i < N1; i++)
        cout << arr1[i] << " ";
    cout << "\nElement " << K1 << " found: " << (solution.searchInSorted(arr1, N1, K1) == 1 ? "Yes" : "No") << endl;

    int arr2[] = {10, 20, 30, 40, 50};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    int K2 = 25;
    cout << "Array: ";
    for (int i = 0; i < N2; i++)
        cout << arr2[i] << " ";
    cout << "\nElement " << K2 << " found: " << (solution.searchInSorted(arr2, N2, K2) == 1 ? "Yes" : "No") << endl;

    int arr3[] = {-5, 0, 3, 9, 12};
    int N3 = sizeof(arr3) / sizeof(arr3[0]);
    int K3 = 0;
    cout << "Array: ";
    for (int i = 0; i < N3; i++)
        cout << arr3[i] << " ";
    cout << "\nElement " << K3 << " found: " << (solution.searchInSorted(arr3, N3, K3) == 1 ? "Yes" : "No") << endl;

    return 0;
}
