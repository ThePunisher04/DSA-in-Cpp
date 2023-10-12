//LC-239

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
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        //first window of k size
        for(int i=0; i<k; i++){
            //chote element remove krdo, 
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                //back se delete isiliye kar rahe hai, kyuki back mei chote elements pade hai
                dq.pop_back();
            }
            //inserting index, so tht we can checkout of window element
            dq.push_back(i);
        }

        //store answer for first window
        ans.push_back(nums[dq.front()]);

        //remaining windows ko process
        for(int i=k; i<nums.size(); i++) {
            //out of window element ko remove krdia 
            if(!dq.empty() && i-dq.front() >= k) {
                dq.pop_front();
            }

            //ab ferse current element k liyue chotte element 
            //ko remove krna h 
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                //back se delete isiliye kar rahe hai, kyuki back mei chote elements pade hai
                dq.pop_back();
            }
            //inserting index, so tht we can checkout of window element
            dq.push_back(i);

            //current window ka answer store krna h 
            ans.push_back(nums[dq.front()]);

        }

        return ans;
    
    
    
    }
};