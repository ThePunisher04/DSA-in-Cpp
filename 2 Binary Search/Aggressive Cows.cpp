#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPossibleSolution(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastPosition = stalls[0];
    int size = stalls.size();
    for(int i=0 ; i<size ; i++){
        if(stalls[i] - lastPosition >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPosition = stalls[i];
        }     
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //Write your code here.
    sort(stalls.begin(),stalls.end());
    int start = 0;
    int ans = -1;
    int maxi = -1;
    int size = stalls.size();
    for(int i = 0; i<size ; i++){
        maxi = max(maxi,stalls[i]);
    }
    int end = maxi;
    int mid = start + (end - start) / 2;
    
    while(start <= end){
        if(isPossibleSolution(stalls,k,mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start) /2;
    }
    return ans;
}

int main(){
    vector<int> stalls = {4,2,1,3,6};
    int ans = aggressiveCows(stalls,2);

    cout<<"The largest minimum distance of aggressive cows is : "<<ans<<endl;

    return 0;
}