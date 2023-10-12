#include <iostream>
using namespace std;

int getSum(int *arr, int size)
{
    if (size == 0)
        return 0;

    if (size == 1)
        return arr[0];

    int sumOfRemainingPart = getSum(arr + 1, size - 1);
    return arr[0] + sumOfRemainingPart;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int sum = getSum(arr, size);
    cout << "The sum of the array is : " << sum << endl;
    return 0;
}