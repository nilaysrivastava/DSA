// Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

// Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
// Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].
// Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.

// Examples:

// Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
// Output: 6, 8
// Explanation: Floor of 7 is 6 and ceil of 7 is 8.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints :
// 1 ≤ arr.size ≤ 105
// 1 ≤ arr[i], x ≤ 106

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int fl;
    int floor = INT_MIN;
    int cl;
    int ceil = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= x)
        {
            fl = arr[i];
            floor = max(fl, floor);
        }
        if (arr[i] >= x)
        {
            cl = arr[i];
            ceil = min(cl, ceil);
        }
    }
    if (floor == INT_MIN)
        floor = -1;
    if (ceil == INT_MAX)
        ceil = -1;
    return {floor, ceil};
}