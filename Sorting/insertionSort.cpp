// Insertion Sort

#include <stdio.h>
#include <math.h>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

#include <bits/stdc++.h>
class Solution
{
public:
    void insert(int arr[], int i, int n)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
    }

public:
    void insertionSort(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            insert(arr, i, n);
        }
    }
};

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
        ob.insertionSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}
