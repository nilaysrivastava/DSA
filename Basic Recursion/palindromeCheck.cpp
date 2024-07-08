// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

#include <iostream>
#include <string>
#include <cctype>

// Function to check if a string is a palindrome
bool isPalindrome(std::string s)
{
    std::string filtered;
    for (char c : s)
    {
        if (std::isalnum(c))
        {
            filtered += std::tolower(c);
        }
    }
    int left = 0;
    int right = filtered.length() - 1;
    while (left < right)
    {
        if (filtered[left] != filtered[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// Main function to test the isPalindrome function
int main()
{
    std::string test1 = "A man, a plan, a canal: Panama";
    std::string test2 = "race a car";

    std::cout << "Test 1: " << (isPalindrome(test1) ? "True" : "False") << std::endl;
    std::cout << "Test 2: " << (isPalindrome(test2) ? "True" : "False") << std::endl;

    return 0;
}
