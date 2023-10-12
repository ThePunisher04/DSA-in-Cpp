//LC-53

// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

//Intuition
//ya to meri max subarrray mid ke left mei hogi, ya to mid ke right mei hogi, ya fir mid ko cross karke hogi (kuch part left mei and kuch part right mei)

class Solution {
    //Time Complexity -> O(n*logn)
    //Space Complexity -> O(logn)

    //if probelm is solved in O(n) TC, then it is called KADANE'S ALGORITHM
public:
    int maxSumArrayHelper(vector<int>&v, int start, int end){
        if(start==end)
            return v[start];
        
        int maxLeftBorderSum = INT_MIN;
        int maxRightBorderSum = INT_MIN;
        
        int mid = start + (end - start) / 2;
        
        int maxLeftSum = maxSumArrayHelper(v,start,mid);
        int maxRightSum = maxSumArrayHelper(v,mid+1,end);
        
        //Max Cross Border Sum
        int leftBorderSum = 0;
        int rightBorderSum = 0;
        
        for(int i = mid ; i >= start ; i--){
            leftBorderSum += v[i];
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }
        
        for(int i = mid + 1; i <= end ; i++){
            rightBorderSum += v[i];
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }
        
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(crossBorderSum, max(maxLeftSum,maxRightSum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSumArrayHelper(nums,0,nums.size()-1);
    }
};