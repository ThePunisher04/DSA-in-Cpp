#include <iostream>
using namespace std;

int getPivot(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int binarySearch(int arr[], int first, int last, int key)
{
    int start = first;
    int end = last;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int searchInRotatedSortedArray(int arr[], int size, int key)
{
    int pivot = getPivot(arr, size);

    if (key >= arr[pivot] && key <= arr[size - 1])
    {
        return binarySearch(arr, pivot, size - 1, key);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, key);
    }
    return -1;
}

int main()
{
    int arr[] = {70, 80, 90, 100, 10, 20, 30, 40, 50, 60};
    int index = searchInRotatedSortedArray(arr, 10, 50);
    cout << "The element is present at index : " << index << endl;

    return 0;
}