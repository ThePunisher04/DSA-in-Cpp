#include <iostream>
using namespace std;

int search(int *arr, int start, int end, int &key)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        return search(arr, start + 1, end, key);
    }
    else
    {
        return search(arr, start, end - 1, key);
    }
}

int main()
{
    int arr[] = {16, 28, 36, 45, 54, 62, 77, 88, 97, 101};
    int size = 10;
    int key = 888;
    int index = search(arr, 0, size - 1, key);

    if (index != -1)
    {
        cout << "Element (" << key << ") found at index -> " << index << endl;
    }
    else
        cout << "Key not present in array" << endl;
    return 0;
}