#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//DOUBLING SEARCH
//GALLOPING SEARCH
//STRAZIK SEARCH

// application->
// very large arrays... infinite arrays... unbounded arrays 
//better than logn time (binary search)... better if key is in near beginning
// iss large array mei ek choti subarray nikalo jisme element guaranteed ho, fir usme binary search laga do

// TIME COMPLEXITY -> O(logm) for while loop where m is the stopping index of i ; O(log(2^(logm-1))

int binary_search(int arr[], int start, int end, int key){
    while(start <= end){
        if(key == arr[mid]){
            return mid;
        }
        else if(key > arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
    {
        return 0;
    }
    int i = 1;
    while (i < n && arr[i] <= x)
    {
        i = i * 2;
    }
    return binary_search(arr, i / 2, min(i, x - 1), x);
}

int main()
{
    return 0;
}