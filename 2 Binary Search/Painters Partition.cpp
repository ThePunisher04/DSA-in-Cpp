#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> &boards, int k, int mid){
    int painterCount = 1;
    int boardSum = 0;
    int size = boards.size();
    
    for(int i = 0 ; i < size ; i++){
        if(boardSum + boards[i] <= mid){
            boardSum += boards[i];
        }
        else{
            painterCount++;
            if(painterCount > k || boards[i] > mid){
                return false;
            }
            boardSum = boards[i];
        }
    }
    return true;
}

int painterPartition(vector<int> &boards, int k)
{
    //    Write your code here.
    int size = boards.size();
    int start = 0;
    int sum = 0;
    for(int i = 0; i < size ; i++){
        sum += boards[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start) / 2;
    
    while(start <= end){
        if(isPossibleSolution(boards,k,mid)){
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
    vector<int> boards = {5,5,5,5};
    int ans = painterPartition(boards,2);

    cout<<"The minimum amount of time required to paint consecutive boards is : "<<ans<<endl;

    return 0;
}