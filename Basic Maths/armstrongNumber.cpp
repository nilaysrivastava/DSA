// Given an integer N, return true it is an Armstrong number otherwise return false.
// An Amrstrong number is a number that is equal to the sum of its own digits each raised
// to the power of the number of digits.

// Example 1:
// Input:N = 153
// Output:True
// Explanation: 13+53+33 = 1 + 125 + 27 = 153

// Example 2:
// Input:N = 371
// Output: True
// Explanation: 33+53+13 = 27 + 343 + 1 = 371

#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int num)
{
    // Calculate the number of
    // digits in the given number
    int k = to_string(num).length();
    // Initialize the sum of digits
    // raised to the power of k to 0
    int sum = 0;
    // Copy the value of the input
    // number to a temporary variable n
    int n = num;
    // Iterate through each
    // digit of the number
    while (n > 0)
    {
        // Extract the last
        // digit of the number
        int ld = n % 10;
        // Add the digit raised to
        // the power of k to the sum
        sum += pow(ld, k);
        // Remove the last digit
        // from the number
        n = n / 10;
    }
    // Check if the sum of digits raised to
    // the power of k equals the original number
    return sum == num ? true : false;
}

int main()
{
    int number = 153;
    if (isArmstrong(number))
    {
        cout << number << " is an Armstrong number." << endl;
    }
    else
    {
        cout << number << " is not an Armstrong number." << endl;
    }
    return 0;
}
