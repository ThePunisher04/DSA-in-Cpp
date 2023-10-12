#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

long long int divideUsingBS(long long int dividend, long long int divisor)
{
    if(dividend == 0 && divisor != 0){
        return 0;
    }
    if (divisor == 0)
    {
        return -101;
    }
    long long int start = 0;
    long long int end = abs(dividend);
    long long int quotient = -1;
    long long int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (abs(divisor * mid) == abs(dividend))
        {
            //perfect divison
            return mid;
        }
        else if (abs(divisor * mid) > abs(dividend))
        {
            // left search
            end = mid - 1;
        }
        else
        {
            // divisor*mid < dividend (non-perfect division)
            // right search
            quotient = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return quotient;
}

int main()
{
    long long int dividend = 0;
    long long int divisor = 10;
    long long int ans = divideUsingBS(dividend, divisor);

    if (ans == -101)
    {
        cout << "Quotient is undefined" << endl;
    }

    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
    {
        cout << "The quotient is : " << ans << endl;
    }
    else if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    {
        cout << "The quotient is : " << -ans << endl;
    }

    return 0;
}