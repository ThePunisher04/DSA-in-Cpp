//LC-448

// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> count(nums.size()+1,0);
        vector<int> ans;
        int size = nums.size();
        for(int i=0; i<size; i++){
            count[nums[i]]++;
        }
        for(int i=1; i<count.size();i++){
            if(count[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};