// Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

// Example 1:

// Input:
// N = 4
// A[] = {0,1,0,1}
// Output: 4
// Explanation: The array from index [0...3]
// contains equal number of 0's and 1's.
// Thus maximum length of subarray having
// equal number of 0's and 1's is 4.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxLen(int A[], int n)
    {
        unordered_map<int, int> map;
        int csum = 0;
        int ans = 0; //max length of subarray with 0 sum
        
        for(int i = 0 ; i < n ; i++){
            int val = A[i] == 0 ? -1 : 1;
            csum += val;
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
