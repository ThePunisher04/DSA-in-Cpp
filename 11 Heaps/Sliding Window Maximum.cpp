// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7


class Solution {
    //Time complexity -> O(n*logn)
    //Space complexity -> O(n)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;    //<value, index>
        vector<int> ans;

        //consider first window
        for(int i = 0 ; i < k ; i++){
            pq.push({nums[i], i});
        }

        //store max of first window
        ans.push_back(pq.top().first);

        //consider the rest of the windows
        for(int i = k ; i < nums.size() ; i++){
            pq.push({nums[i], i});

            //remove if maximum elements are from previous windows
            while(pq.top().second <= i-k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};