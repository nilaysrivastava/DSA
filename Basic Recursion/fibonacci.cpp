// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
// such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

// Example 1:
// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

// Example 2:
// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

// Example 3:
// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

// Constraints:

// 0 <= n <= 30

#include <iostream>

// Solution class containing the Fibonacci function
class Solution
{
public:
    long long fib(long long n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        long long a = 1, b = 1, result = 1;
        for (long long i = 3; i <= n; i++)
        {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};

// Main function to test the fib function
int main()
{
    Solution solution;

    long long test1 = 10; // Example: fib(10) should return 55
    long long test2 = 50; // Example: fib(50) should return a large number (12586269025)

    std::cout << "Fib(10): " << solution.fib(test1) << std::endl;
    std::cout << "Fib(50): " << solution.fib(test2) << std::endl;

    return 0;
}
