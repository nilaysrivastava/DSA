// Given an integer x, return true if x is a
// palindrome
// and false otherwise.

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-.
// Therefore it is not a palindrome.

// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

// Constraints:
// -231 <= x <= 231 - 1

#include <iostream>
#include <string>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Negative numbers and numbers ending with 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        long long rev = 0;
        long long n = x;

        // Reverse the number
        while (n > 0)
        {
            long long ld = n % 10;
            rev = (rev * 10) + ld;
            n = n / 10;
        }

        return x == rev;

        //              OR

        std::string str = std::to_string(x);

        int left = 0;
        int right = str.length() - 1;

        while (left < right)
        {
            if (str[left] != str[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    int number;

    // Prompt the user to enter an integer
    std::cout << "Enter an integer to check if it is a palindrome: ";
    std::cin >> number;

    // Call the isPalindrome function and store the result
    bool result = solution.isPalindrome(number);

    // Output the result
    if (result)
    {
        std::cout << number << " is a palindrome." << std::endl;
    }
    else
    {
        std::cout << number << " is not a palindrome." << std::endl;
    }

    return 0;
}
