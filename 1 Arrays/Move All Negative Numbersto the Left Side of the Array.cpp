#include <iostream>
using namespace std;

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void moveNeg(int arr[], int size)
{
    int low = 0;
    int high = size - 1;

    while (low < high)
    {
        if (arr[low] < 0)
        {
            low++;
        }
        else if (arr[high] > 0)
        {
            high--;
        }
        else
        {
            swap(arr[low], arr[high]);
        }
    }
}

int main()
{
    int a[] = {1, 2, -3, 4, -5, 6};
    int n = sizeof(a) / sizeof(int);
    displayArray(a,n);
    moveNeg(a, n);
    displayArray(a,n);
    return 0;
}