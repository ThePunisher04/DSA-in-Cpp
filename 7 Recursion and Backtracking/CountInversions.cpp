#include <iostream>
#include <vector>
using namespace std;

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

//Approach-1 : TWO POINTER
    //TC = O(n2)
    //SC = O(1)

int invCount = 0;
for(int i=0 ; i<n ; i++){
    for(int j=i+1 ; j<n ; j++){
        if(arr[i] > arr[j]){
            invCount++;
        }
    }
}

//Approach-2 : MERGE SORT
    //Time complexity -> O(n*logn)
    //Space complexity -> O(n) for temp array

long merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end){
    int i = start; //pointing to left array
    int j = mid+1; //pointing to right array
    int k = start; //pointing to temp array
    long c = 0;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{ 
            // arr[i] > arr[j] -> count inversion case
            temp[k++] = arr[j++];
            c += mid - start + 1;
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= end){
        temp[k++] = arr[j++];
    }

    while(start <= end){
        arr[start] = temp[start];
        start++;
    }

    return c;
}

long mergeSort(vector<int>& arr, vector<int>& temp, int start, int end){
    if(start >= end) return 0;
    int c = 0;
    int mid = start + (end-start)/2;

    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid+1, end);
    c += merge(arr, temp, start, mid, end);

    return c;
}

long countInversions(vector<int> arr){
    long c = 0;
    vector<int> temp(arr.size(), 0);
    c = mergeSort(arr, temp , 0, arr.size() - 1);
    return c;
}

int main(){
    vector<int> arr = {8,4,2,1};
    cout << "Count of Inversions: "<< countInversions(arr)<< endl;
}