// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:
// Input: x = 123
// Output: 321

// Example 2:
// Input: x = -123
// Output: -321

// Example 3:
// Input: x = 120
// Output: 21

// Constraints:
// -231 <= x <= 231 - 1

#include <iostream>
#include <climits> // For INT_MAX and INT_MIN

class Solution
{
public:
    // Function to reverse the digits of an integer
    int reverse(int x)
    {
        // Use long long to handle overflow issues
        long long rev = 0;

        // Loop until all digits are processed
        while (x != 0)
        {
            // Get the last digit of x
            int ld = x % 10;

            // Append the last digit to rev
            rev = rev * 10 + ld;

            // Remove the last digit from x
            x = x / 10;
        }

        // Check for overflow. If rev exceeds the range of int, return 0
        if (rev > INT_MAX || rev < INT_MIN)
            return 0;

        // Cast rev back to int before returning
        return (int)rev;
    }
};

int main()
{
    Solution solution;
    int number;

    // Prompt the user to enter an integer
    std::cout << "Enter an integer to reverse: ";
    std::cin >> number;

    // Call the reverse function and store the result
    int reversedNumber = solution.reverse(number);

    // Output the reversed number
    std::cout << "Reversed number: " << reversedNumber << std::endl;

    return 0;
}