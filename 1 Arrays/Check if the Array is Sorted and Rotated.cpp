#include <bits/stdc++.h>
#include <vector>
using namespace std;

//LC-1752

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isRotatedAndSorted(vector<int> &arr, int n){
    int pairCount = 0;
    for(int i=0 ;i<n ; i++){
        if(arr[i]>arr[i+1]){
            pairCount++;
        }
    }
    if(arr[n-1]>arr[0]){
        pairCount++;
    }
    
    return pairCount<=1;
}

int main(){

    vector<int> arr = {4,5,1,2,3};
    bool ans = isRotatedAndSorted(arr,5);
    cout<<ans<<endl;

    return 0;
}