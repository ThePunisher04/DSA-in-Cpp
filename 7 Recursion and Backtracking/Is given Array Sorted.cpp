#include <iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
    if (size <= 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    isSorted(arr + 1, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 60, 7, 8, 9};
    int size = 9;
    bool ans = isSorted(arr, size);
    if (ans)
        cout << "The array is sorted" << endl;
    else
        cout << "The array is not sorted" << endl;
    return 0;
}

#include <iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int> &arr, int& n, int i) {
  //base case
  if(i == n-1) {
    return true;
  }

  //1 case solve krna h
  if(arr[i+1] <= arr[i])
    return false;

  //baaki recursio sambhal lega
  bool ans = checkSorted(arr, n, i+1);
  return ans;

}

int main() {
  vector<int> v{4,3,1,2,4,4};
  int n = v.size();
  int i = 0;
  bool isSorted = checkSorted(v, n, i);

  if(isSorted) {
    cout << "Array is sorted" << endl;
  }
  else {
    cout << "Array is not sorted" << endl;
  }

  return 0;
}