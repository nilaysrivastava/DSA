// Given a positive integer N., The task is to find the value of Σi from 1 to N F(i)
// where function F(i) for the number i is defined as the sum of all divisors of i.

// Example 1:

// Input:
// N = 4
// Output:
// 15
// Explanation:
// F(1) = 1
// F(2) = 1 + 2 = 3
// F(3) = 1 + 3 = 4
// F(4) = 1 + 2 + 4 = 7
// ans = F(1) + F(2) + F(3) + F(4)
//     = 1 + 3 + 4 + 7
//     = 15

// Example 2:

// Input:
// N = 5
// Output:
// 21
// Explanation:
// F(1) = 1
// F(2) = 1 + 2 = 3
// F(3) = 1 + 3 = 4
// F(4) = 1 + 2 + 4 = 7
// F(5) = 1 + 5 = 6
// ans = F(1) + F(2) + F(3) + F(4) + F(5)
//     = 1 + 3 + 4 + 7 + 6
//     = 21

// Your Task:
// You don't need to read input or print anything. Your task is to complete the
// function sumOfDivisors() which takes an integer N as an input parameter and
// returns an integer.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 10^6

#include <iostream>
using namespace std;

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum = 0;

        // Iterating from 1 to N.
        for (int i = 1; i <= N; ++i)
            // Calculating and accumulating the sum of divisors.
            sum += (N / i) * i;

        // Returning the sum of divisors.
        return sum;
    }
};

int main()
{
    Solution solution;

    // Test cases
    int N1 = 4;
    cout << "Sum of divisors for N = " << N1 << " is " << solution.sumOfDivisors(N1) << endl;

    int N2 = 5;
    cout << "Sum of divisors for N = " << N2 << " is " << solution.sumOfDivisors(N2) << endl;

    int N3 = 66600;
    cout << "Sum of divisors for N = " << N3 << " is " << solution.sumOfDivisors(N3) << endl;

    return 0;
}
