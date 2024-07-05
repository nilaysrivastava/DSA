// Given an array arr[] of size n of non-negative integers.
// Each array element represents the maximum length of the jumps that
// can be made forward from that element. This means if arr[i] = x,
// then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array
// starting from the first element. If an element is 0,
// then you cannot move through that element.
// Note:  Return -1 if you can't reach the end of the array.

// Examples :

// Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}, n = 11
// Output: 3
// Explanation:First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last.

// Input: arr = {1, 4, 3, 2, 6, 7}, n = 6
// Output: 2
// Explanation: First we jump from the 1st to 2nd element and then jump to the last element.

// Input: arr = {0, 10, 20}, n = 3
// Output: -1
// Explanation: We cannot go anywhere from the 1st element.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 0 ≤ arr[i] ≤ 10^7
// 1 ≤ n ≤ 10^7

#include <iostream>
#include <algorithm> // For std::max
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // If array size is 0 or 1, no jumps are needed
        if (n <= 1)
            return 0;

        // If the first element is 0, no further jumps are possible
        if (arr[0] == 0)
            return -1;

        int maxReach = arr[0]; // Maximum index that can be reached
        int steps = arr[0];    // Steps remaining at current jump
        int jumps = 1;         // Number of jumps taken

        for (int i = 1; i < n; i++)
        {
            // If we have reached the last index, return the number of jumps
            if (i == n - 1)
                return jumps;

            // Update the maximum reach from the current position
            maxReach = max(maxReach, i + arr[i]);

            // Decrease steps to reach the current index
            steps--;

            // If no more steps left, jump to the next position and increment jumps
            if (steps == 0)
            {
                jumps++;

                // If unable to reach further from current position, return -1
                if (i >= maxReach)
                    return -1;

                // Reset steps to the difference between maxReach and current index
                steps = maxReach - i;
            }
        }

        // If unable to reach the last index
        return -1;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    int arr1[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Minimum number of jumps for arr1: " << solution.minJumps(arr1, n1) << endl;

    // Test case 2
    int arr2[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Minimum number of jumps for arr2: " << solution.minJumps(arr2, n2) << endl;

    // Test case 3
    int arr3[] = {2, 1, 3, 1, 1, 0, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Minimum number of jumps for arr3: " << solution.minJumps(arr3, n3) << endl;

    return 0;
}
