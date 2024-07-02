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
