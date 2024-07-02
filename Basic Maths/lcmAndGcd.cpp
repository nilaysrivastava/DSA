// Given two integers a and b, write a function lcmAndGcd() to compute their LCM and GCD. The function takes two integers a and b as input and returns a list containing their LCM and GCD.

// Examples:

// Input: a = 5 , b = 10
// Output: 10 5
// Explanation: LCM of 5 and 10 is 10, while thier GCD is 5.

// Input: a = 14 , b = 8
// Output: 56 2
// Explanation: LCM of 14 and 8 is 56, while thier GCD is 2.

// Expected Time Complexity: O(log(min(a, b))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= a, b <= 109

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<long long> lcmAndGcd(long long A, long long B)
    {
        long long gcd, lcm;
        long long a = A;
        long long b = B;
        while (a > 0 && b > 0)
        {
            if (a > b)
                a = a % b;
            else
                b = b % a;
        }
        if (a == 0)
            gcd = b;
        else
            gcd = a;
        lcm = (A * B) / gcd;
        return {lcm, gcd};
    }
};

int main()
{
    Solution solution;
    long long A, B;
    cout << "Enter two numbers: ";
    cin >> A >> B;

    vector<long long> result = solution.lcmAndGcd(A, B);

    cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl;

    return 0;
}
