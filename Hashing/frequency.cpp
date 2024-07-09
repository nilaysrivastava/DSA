// Given an array arr[] of n positive integers which can contain integers from 1 to p
// where elements can be repeated or can be absent from the array.
// Your task is to count the frequency of all numbers from 1 to n.
// Do modify the array in-place changes in arr[], such that arr[i] = frequency(i)
// and assume 1-based indexing.

// Note: The elements greater than n in the array can be ignored for counting.

// Examples

// Input: n = 5 arr[] = {2, 3, 2, 3, 5} p = 5
// Output: 0 2 2 0 1
// Explanation: Counting frequencies of each array element We have: 1 occurring 0 times. 2 occurring 2 times. 3 occurring 2 times. 4 occurring 0 times. 5 occurring 1 time.

// Input: n = 4  arr[] = {3,3,3,3} p = 3
// Output: 0 0 4 0
// Explanation: Counting frequencies of each array element We have: 1 occurring 0 times. 2 occurring 0 times. 3 occurring 4 times. 4 occurring 0 times.

// Input: n = 2 arr[] = {8,9} p = 9
// Output: 0 0
// Explanation: Counting frequencies of each array element We have: 1 occurring 0 times. 2 occurring 0 times. Since here P=9, but there are no 9th Index present so can't count the value.

// Your Task:
// You don't need to read input or print anything. Complete the function frequencyCount() that takes the array arr, and integers n, and p as input parameters and modify the array in-place to denote the frequency count of each element from 1 to N.

// Expected time complexity: O(N)
// Expected auxiliay space: O(1)

// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ p ≤ 4*104
// 1 <= arr[i] <= p

#include <iostream>
#include <vector>

class Solution
{
public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(std::vector<int> &arr, int N, int P)
    {
        // Initialize a hash vector of size N with all zeros.
        std::vector<long long> hash(N, 0);

        // Traverse the input array and update the hash vector.
        for (long long i = 0; i < N; i++)
        {
            // Check if the current element is within the range [1, N].
            if (arr[i] >= 1 && arr[i] <= N)
            {
                // Increment the count of the element in the hash vector.
                hash[arr[i] - 1]++;
            }
        }

        // Copy the counts from the hash vector back to the original array.
        for (long long i = 0; i < N; i++)
        {
            arr[i] = hash[i];
        }
    }
};

int main()
{
    Solution sol;

    // Example array
    std::vector<int> arr = {2, 3, 2, 3, 5};
    int N = arr.size();
    int P = 5;

    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sol.frequencyCount(arr, N, P);

    std::cout << "Frequency count: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
