//THE DUTCH NATIONAL FLAG PROBLEM
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

void sort012(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while(mid <= high){
        switch (arr[mid])
        {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;
        }
    }
    
}

int main()
{
    int arr[9] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    cout << "BEFORE SORTING" << endl;
    displayArray(arr, 9);
    cout << "AFTER SORTING" << endl;
    sort012(arr, 9);
    displayArray(arr, 9);
}