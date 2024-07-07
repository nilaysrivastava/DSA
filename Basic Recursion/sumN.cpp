// Given an integer n, calculate the sum of series 13 + 23 + 33 + 43 + … till n-th term.

// Example 1:

// Input:
// n=5
// Output:
// 225
// Explanation:
// 13+23+33+43+53=225
// Example 2:

// Input:
// n=7
// Output:
// 784
// Explanation:
// 13+23+33+43+53+63+73=784

// Your Task:
// You don't need to read input or print anything. Your task is to complete the
// function sumOfSeries() which takes the integer n as a parameter and returns
// the sum of the cubes of the first n natural numbers.

// Expected Time Complexity: O(1)
// Expected Auxillary Space: O(1)

// Constraints:
// 1<=n<=50000

#include <iostream>

class Solution
{
public:
    long long sumOfSeries(long long n)
    {
        long long m = n * (n + 1) / 2;
        long long sum = m * m;
        return sum;
    }
};

int main()
{
    Solution solution;
    long long n = 5; // You can change this value to test with different numbers
    std::cout << "Sum of series for n = " << n << " is: " << solution.sumOfSeries(n) << std::endl;
    return 0;
}
