// Print numbers from N to 1 (space separated) without the help of loops.

// Example 1:

// Input:
// N = 10
// Output: 10 9 8 7 6 5 4 3 2 1

// Your Task:
// This is a function problem. You only need to complete the function printNos() that takes N as parameter and prints number from N to 1 recursively. Don't print newline, it will be added by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N) (Recursive).

// Constraint
// 1<=n<=1000

#include <iostream>

class Solution
{
public:
    void printNos(int N)
    {
        if (N <= 0)
            return;
        std::cout << N << " ";
        printNos(N - 1);
        return;
    }
};

int main()
{
    Solution solution;
    int N = 10; // You can change this value to test with different numbers
    solution.printNos(N);
    std::cout << std::endl; // Print a new line at the end for better readability
    return 0;
}
