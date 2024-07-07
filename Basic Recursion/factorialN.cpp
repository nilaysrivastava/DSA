// A number n is called a factorial number if it is the factorial of a positive integer. For example, the first few factorial numbers are 1, 2, 6, 24, 120,
// Given a number n, the task is to return the list/vector of the factorial numbers smaller than or equal to n.

// Examples:

// Input: n = 3
// Output: 1 2
// Explanation: The first factorial number is 1 which is less than equal to n. The second number is 2 which is less than equal to n,but the third factorial number is 6 which is greater than n. So we print only 1 and 2.

// Input: n = 6
// Output: 1 2 6

// Explanation: The first three factorial numbers are less than equal to n but the fourth factorial number 24 is greater than n. So we print only first three factorial numbers.
// Expected Time Complexity: O(k), Where k is the number of factorial numbers.
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=n<=1018

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<long long> factorialNumbers(long long N)
    {
        std::vector<long long> result;
        long long factorial = 1;
        for (long long i = 1; factorial <= N; i++)
        {
            result.push_back(factorial);
            factorial *= (i + 1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    long long N = 100; // You can change this value to test with different numbers
    std::vector<long long> factorials = solution.factorialNumbers(N);

    std::cout << "Factorial numbers up to " << N << " are: ";
    for (long long num : factorials)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
