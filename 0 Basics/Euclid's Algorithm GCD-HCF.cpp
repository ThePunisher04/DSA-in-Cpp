#include <iostream>
using namespace std;

// Formulae:-

// GCD(a, b) = GCD(a - b, b)
// GCD(a, b) = GCD(a % b, b)

// LCM(a, b) * GCD(a, b) = a * b

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    cout << gcd(24, 72) << endl;
}