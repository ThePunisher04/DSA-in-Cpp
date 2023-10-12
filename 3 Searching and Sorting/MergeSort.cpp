#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    // copy values from main array into left array
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    // copy values from main array into right array
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    // START COMPARING
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;  //catch

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        // single element or invalid case
        return;
    }

    int mid = s + (e - s) / 2;

    // sort the left array
    mergeSort(arr, s, mid);

    // sort the right array
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {7, 2, 4, 1, 8, 3, 9, 5};
    int n = 8;
    int s = 0;
    int e = n - 1;
    cout << "BEFORE SORTING" << endl;
    printArray(arr, n);

    mergeSort(arr, s, e);

    cout << "AFTER SORTING" << endl;
    printArray(arr, n);
}