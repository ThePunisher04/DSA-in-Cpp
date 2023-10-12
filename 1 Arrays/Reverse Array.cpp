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

void reverseArray(int arr[], int size)
{

    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int arr[100];
    int size;
    cout << "Enter the size of the array :" << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << endl;
    // Before reversing
    cout << "Before reversing" << endl;
    displayArray(arr, size);

    cout << endl;
    // After reversing
    cout << "After reversing" << endl;
    reverseArray(arr, size);
    displayArray(arr, size);
    cout << endl;
}