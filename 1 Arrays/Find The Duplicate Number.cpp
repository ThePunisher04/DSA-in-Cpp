//GFG

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //XOR Method
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }
        for(int i=1; i<nums.size(); i++){
            ans = ans ^ i;
        }
        return ans;
    }
};

//Negative Marking Method
int findDuplicate(vector<int>& nums){
    int ans = -1;
    for(int i = 0 ; i < nums.size() ; i++){
        int index = abs(nums[i]);
        if(nums[index] < 0){
            //already visited
            ans = index;
            break;
        }
        else{
            //not visited -> mark negative
            nums[index] = nums[index] * (-1);
        }
    }
    return ans;
}

//Positioning Method
/* 0th location pe jo bhi element pada hua hoga usko sahi position pe leke jana hai
agar vo apni sahi position pe nahi hai, to usko uski sahi position pe leke jao
agar vo already apni sahi position pe hai, iska matlab 0th location vala element duplicate hai */
//answer hamesha 0th index pe hi milega iss approach se

int findDuplicate(vector<int>& nums){
    while(nums[0] != nums[nums[0]]){
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}


