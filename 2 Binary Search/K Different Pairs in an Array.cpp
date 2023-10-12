// LC-532

// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.


// BRUTE-FORCE approach
//consider each and every pair and check diff
// TC-> O(n2)




//BINARY SEARCH approach
//Time complexity -> O(nlogn) for sorting + O(nlogn) for searching nums[j] element for every nums[i] element (n) through binary search (logn) ==> O(n*logn)
//sort kardo pehle
// ab mere pass nums[i] vala element to hai hi, agar mujhe aage ek aisa element nums[j] mil jaye joki (k + nums[i]) ke barabar ho to main bol sakta hun ki mujhe ek pair mil gaya
//start hamesha curr index ke 1 aage se initialize hoga; end hamesha sab (size-1) rahega for every search request

class Solution {
public:
    //binary search vala exact logic
    int binSearch(vector<int> & nums, int start, int key){
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;

        while(start <= end){
            if(key == nums[mid]){
                return mid;
            }
            else if(key > nums[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;

        for(int i=0 ; i<nums.size() ; i++){
            //right subarray mein " nums[i] + k " dhundna hai
            //" nums[i] + k " matlab nums[j] -> question reframe kar diya hai
            //right subarray sorted hai, apply binary search
            int index = binSearch(nums, i+1, nums[i] + k);
            if(index != -1){
                ans.insert({nums[i], nums[i] + k});
            }
        }

        return ans.size();
    }
};


// TWO-POINTER with SLIDING WINDOW approach
//Time complexity -> O(nums.size()) + O(n*logn) = O(n*logn)
// i badhane se diff kam hoga
// j badhane se diff zyada hoga

int findPairs(vector<int>& nums, int k){
    set <pair<int, int> > ans;
    //set isiliye use kar rahe taki distinct pairs store ho
    //baad mein jitne distinct pairs honge vo set ke size se bata denge
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = 1;
    while(j < nums.size()){
        int diff = nums[j] - nums[i];
        if(diff == k){
            ans.insert({nums[i], nums[j]});
            i++; j++;
        }
        else if(diff > k){
            ++i;
        }
        else{
            //diff < k
            j++;
        }

        if(i == j){
            //pointing to same index location -> not allowed
            j++;
        }
    }

    return ans.size();
}