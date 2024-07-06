// Print numbers from 1 to n without the help of loops.
// You only need to complete the function printNos()
// that takes N as parameter and prints number from
// 1 to N recursively.

// Don't print newline, it will be added by the driver code.

// Examples

// Input: n = 10
// Output: 1 2 3 4 5 6 7 8 9 10

// Input: n = 5
// Output: 1 2 3 4 5

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n) (Recursive).

// Constraints:
// 1 <= n <= 1000

#include <iostream>
using namespace std;

class Solution
{
public:
    // Method to print numbers from 1 to N
    void printNos(int N)
    {
        // Base case: if N is less than or equal to 0, return
        if (N <= 0)
            return;

        // Recursive call with N-1
        printNos(N - 1);

        // Print the current number after the recursive call
        cout << N << " ";
    }
};

int main()
{
    Solution solution;
    int N;
    cout << "Enter a number: ";
    cin >> N;
    solution.printNos(N);
    cout << endl;
    return 0;
}
