//LC-442

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<bool> visited(size+1,false);
        vector<int> ans;
        for(int i = 0 ; i < size ; i++){
            if(visited[nums[i]]==true){
                ans.push_back(nums[i]);
            }
            else{
                visited[nums[i]]=true;
            }
        }
        return ans;
    }
};