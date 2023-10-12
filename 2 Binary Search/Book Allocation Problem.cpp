//BOOK ALLOCATION PROBLEM
#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>

bool isPossibleSolution(vector<int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for(int i = 0 ; i < n ; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            else{
                pageSum = 0;
                pageSum = arr[i];
            }
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {

    int start = 0;
    int ans = -1;
    int sum = 0;
    for(int i = 0; i < n ; i++){
        sum += arr[i];
    }
    int end = sum;
    int mid = start + (end - start) / 2;
    
    while(start <= end){
        if(isPossibleSolution(arr,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main(){
    vector<int> books = {10,20,30,40};
    int ans = allocateBooks(books,4,2);

    cout<<"The minimum number of maximum pages assigned to a student is : "<<ans<<endl;

    return 0;
}