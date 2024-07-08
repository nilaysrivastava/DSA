// Print GFG n times without the loop.

// Example:

// Input:
// 5
// Output:
// GFG GFG GFG GFG GFG

// Your Task:
// This is a function problem. You only need to complete the function printGfg()
// that takes N as parameter and prints N times GFG recursively.
// Don't print newline, it will be added by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N) (Recursive).

// Constraint:
// 1<=N<=1000

#include <iostream>
using namespace std;

class Solution
{
public:
    // Method to print "GFG" N times
    void printGfg(int N)
    {
        // Base case: if N is less than or equal to 0, return
        if (N <= 0)
            return;

        // Print "GFG" followed by a space
        cout << "GFG" << " ";

        // Recursive call with N-1
        printGfg(N - 1);
    }
};

int main()
{
    Solution solution;
    int N;

    cout << "Enter a number: ";
    cin >> N;

    solution.printGfg(N);

    cout << endl;
    return 0;
}
