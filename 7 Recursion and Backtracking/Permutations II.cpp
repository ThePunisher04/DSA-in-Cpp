//LC-47
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.


// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

class Solution {
public:
    
    void permuteUniqueHelper(vector<int>&nums, vector<vector<int>>&ans, int start){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int,bool> visited;
        for(int i=start ; i < nums.size() ; i++){
            if(visited.find(nums[i]) != visited.end()){
                //found
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i],nums[start]);
            permuteUniqueHelper(nums,ans,start+1);
            //backtrack
            swap(nums[i],nums[start]);
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUniqueHelper(nums,ans,0);
        return ans;
    }
};