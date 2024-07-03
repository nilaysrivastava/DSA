// Given a number n. Count the number of digits in n which evenly divide n.
// Return an integer, total number of digits of n which divides n evenly.

// Note :- Evenly divides means whether n is divisible by a digit
// i.e. leaves a remainder 0 when divided.

// Examples :

// Input: n = 12
// Output: 2
// Explanation: 1, 2 when both divide 12 leaves remainder 0.

// Input: n = 23
// Output 0
// Explanation: 2 and 3, none of them divide 23 evenly.

// Expected Time Complexity: O(log n)
// Expected Space Complexity: O(1)

// Constraints:
// 1<= n <=105

#include <iostream>

class Solution
{
public:
    int evenlyDivides(int N)
    {
        int original = N;
        int count = 0;

        // Loop through each digit of N
        while (N > 0)
        {
            int digit = N % 10; // Get the last digit

            // Check if the digit is not zero and if it divides the original number evenly
            if (digit != 0 && original % digit == 0)
            {
                count++;
            }

            // Remove the last digit
            N = N / 10;
        }

        return count; // Return the count of digits that evenly divide the original number
    }
};

int main()
{
    Solution solution;
    int number;

    // Prompt the user to enter an integer
    std::cout << "Enter an integer to check its digits: ";
    std::cin >> number;

    // Call the evenlyDivides function and store the result
    int result = solution.evenlyDivides(number);

    // Output the result
    std::cout << "Number of digits in " << number << " that evenly divide it: " << result << std::endl;

    return 0;
}
