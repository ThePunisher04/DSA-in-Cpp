#include <iostream>
using namespace std;

void displayArray(int arr[], int size)
{
    cout << "Your array is :-" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort01(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        while (arr[left] == 0 && left < right)
        {
            left++;
        }
        while (arr[right] == 1 && left < right)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[6] = {0, 1, 1, 0, 1, 0};
    cout << "BEFORE SORTING" << endl;
    displayArray(arr, 6);
    cout << "AFTER SORTING" << endl;
    sort01(arr, 6);
    displayArray(arr, 6);
    return 0;
}