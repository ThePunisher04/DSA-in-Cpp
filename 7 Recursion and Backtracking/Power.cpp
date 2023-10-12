#include <iostream>
using namespace std;

long long int power(long long int a, long long int b)
{
    // Time Complexity -> O(b) = O(n)
    if (b == 0)
    {
        return 1;
    }

    return a * power(a, b - 1);
}

long long int power2(long long int a, long long int b)
{
    // Time Complexity -> O(logn)
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    long long int ans = power(a, b/2);

    if (b & 1)
    {
        // odd exponent
        return a * ans * ans;
    }
    else{
        //even exponent
        return ans * ans;
    }
}

int main()
{
    long long int a = 8;  // base
    long long int b = 12; // exponent
    long long int ans = power2(a, b);
    cout << a << " raised to the power of " << b << " is : " << ans << endl;
    return 0;
}