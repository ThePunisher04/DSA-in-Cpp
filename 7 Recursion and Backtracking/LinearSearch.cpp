#include <iostream>
using namespace std;

int search(int *arr, int size, int index, int &key)
{
    if (size == 0)
        return -1;

    if (arr[0] == key)
        return index;

    int searchAhead = search(arr + 1, size - 1, index + 1, key);
}

int main()
{
    int arr[] = {16, 28, 36, 45, 54, 62, 77, 88, 97, 10};
    int size = 10;
    int key = 777;
    int index = search(arr, size, 0, key);

    if (index != -1)
    {
        cout << "Element (" << key << ") found at index -> " << index << endl;
    }
    else
        cout << "Key not present in array" << endl;
    return 0;
}