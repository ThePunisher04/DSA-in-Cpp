// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> map;
        int csum = 0;
        int ans = 0; //max length of subarray with 0 sum
        
        for(int i = 0 ; i < n ; i++){
            csum += A[i];
            if(csum == 0){
                ans = max(ans, i+1);
            }
            else if(map.find(csum) == map.end()){
                map[csum] = i;
            }
            else{
                //map already has csum
                ans = max(ans, i - map[csum]);
            }
        }
        return ans;
    }
};

