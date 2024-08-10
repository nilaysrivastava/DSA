// Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.

// Examples:

// Input: n = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

// Input: n = 5, arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.

// Input: n = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.

// Expected Time Complexity: O(nLogn).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 ≤ n ≤ 5*105
// 1 ≤ arr[i] ≤ 1018

#include <iostream>
#include <vector>

using namespace std;

// Function to merge two halves and count inversions
long long mergeAndCount(vector<long long> &arr, vector<long long> &temp, int left, int mid, int right)
{
    int i = left; // Starting index for left subarray
    int j = mid;  // Starting index for right subarray
    int k = left; // Starting index to be sorted
    long long inv_count = 0;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid - i); // Count inversions
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray into Original array
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Function to use merge sort and count inversions
long long mergeSortAndCount(vector<long long> &arr, vector<long long> &temp, int left, int right)
{
    long long inv_count = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long countInversions(vector<long long> &arr, int n)
{
    vector<long long> temp(n);
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main()
{
    vector<long long> arr = {2, 4, 1, 3, 5};
    int n = arr.size();
    long long result = countInversions(arr, n);
    cout << "Number of inversions are " << result << endl;
    return 0;
}
