// You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:

// The ith customer gets exactly quantity[i] integers,
// The integers the ith customer gets are all equal, and
// Every customer is satisfied.
// Return true if it is possible to distribute nums according to the above conditions.

 

// Example 1:

// Input: nums = [1,2,3,4], quantity = [2]
// Output: false
// Explanation: The 0th customer cannot be given two different integers.


class Solution {
public:
    
    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity,int ithCustomer) {
        //base case
        if(ithCustomer == quantity.size()){
            return true;
        }
        
        for(int i=0 ; i < counts.size() ; i++){
            if(counts[i] >= quantity[ithCustomer]){
                counts[i] -= quantity[ithCustomer];
                if(canDistributeHelper(counts,quantity,ithCustomer+1)){
                    return true;
                }
                counts[i] += quantity[ithCustomer]; //backtrack
            }
        }
        return false;
    }
    
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countMap;
        
        for(auto num : nums){
            countMap[num]++;
        }
        vector<int> counts;
        for(auto it : countMap){
            counts.push_back(it.second);
        }
        
        //OPTIMIZATION
        //by reverse sorting the quantities array i can determine quickly whether i will be able to fulfill the demands of every cutomer or not
        //coz if we cant satisfy the demand of the most demanding customer then there is no need to check for the rest of the customers, we will return false immediately
        sort(quantity.rbegin(),quantity.rend());
        
        return canDistributeHelper(counts,quantity,0);
    }
};