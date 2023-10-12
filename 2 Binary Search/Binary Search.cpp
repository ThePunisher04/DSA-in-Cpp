#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int index = binarySearch(arr, 10, 70);
    cout<<"The element is present at index : "<<index<<endl;

    return 0;
}