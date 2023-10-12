//LC-198

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
    //Time complexity -> O(2^n) exponential
    //Space complexity -> O(n)
public:
    
    int robHelper(vector<int>& nums, int i){
        //base case
        if(i >= nums.size()){
            return 0;
        }
        
        //solve one case
        int robAmt1 = nums[i] + robHelper(nums, i+2);
        int robAmt2 = 0 + robHelper(nums, i+1);
        
        return max(robAmt1, robAmt2);
    }
    
    int rob(vector<int>& nums) {
        return robHelper(nums,0);
    }
};




#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>& arr,int i, int sum, int &maxi) {
  //base case
  if(i >= arr.size()) {
    //maxi update;
    maxi = max(sum, maxi);
    return;
  }

  //include
  solve(arr,i+2,sum+arr[i] ,maxi );
  //exclude
  solve(arr, i+1, sum, maxi);
}

int main() {
  vector<int> arr{1, 2, 3, 1, 3, 5, 8, 1, 9};
  int sum = 0;
  int maxi = INT_MIN;
  int i = 0;
  solve(arr,i, sum, maxi);

  cout << maxi << endl;

  return 0;
}