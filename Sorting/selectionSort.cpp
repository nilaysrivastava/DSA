// Selection Sort

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    int select(int arr[], int i, int n)
    {
        // code here such that selectionSort() sorts arr[]
        int minidx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minidx])
                minidx = j;
        }
        return minidx;
    }

    void selectionSort(int arr[], int n)
    {
        // code here
        for (int i = 0; i < n - 1; i++)
        {
            int minidx = select(arr, i, n);
            std::swap(arr[minidx], arr[i]);
        }
    }
};

//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000], n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.selectionSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}