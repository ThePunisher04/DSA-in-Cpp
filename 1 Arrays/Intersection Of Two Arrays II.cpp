//LC-350

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(int i=0 ; i < nums1.size() ; i++){
            for(int j=0 ; j < nums2.size() ; j++){
                if(nums1[i] == nums2[j]){
                    nums2[j] = -1;
                    ans.push_back(nums1[i]);
                    break;
                    
                }
            }
        }
        return ans;
    }
};