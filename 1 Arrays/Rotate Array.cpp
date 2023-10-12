#include <bits/stdc++.h>
#include <vector>
using namespace std;

//LC-189

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }
    arr = temp;
    return arr;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    rotateArray(arr, 3);
    display(arr);

    return 0;
}