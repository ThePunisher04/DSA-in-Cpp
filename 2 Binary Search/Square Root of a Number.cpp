// CALCULATING SQUARE ROOT USING BINARY SEARCH... ROOT IS ALSO AN INTEGER...DECIMAL PLACES ARE TRUNCATED

//SEARCH SPACE PATTERN

#include <iostream>
using namespace std;

long long int sqrtInteger(int n)
{
    int start = 0;
    int end = n;
    long long int mid = start + (end - start) / 2;
    long long ans = -1;

    while (start <= end)
    {
        long long square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

double morePrecision(int num, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < num; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int num = 27;
    long long int tempSol = sqrtInteger(num);
    cout<<tempSol<<endl;
    int precision = 3;
    //double root = morePrecision(num, precision, tempSol);
    //cout << "The square root of " << num << " is : " << root << endl;

    return 0;
}