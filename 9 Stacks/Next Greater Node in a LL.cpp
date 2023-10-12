//LC-1019

// You are given the head of a linked list with n nodes.

// For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

// Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

// Example 1:
// Input: head = [2,1,5]
// Output: [5,5,0]

// Example 2:
// Input: head = [2,7,4,3,5]
// Output: [7,0,5,5,0]




// PATTERN -> MONOTONIC STACK 

class Solution {
    //TC=O(N)
    //SC=O(N)
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector <int> ll;
        while(head){
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        vector<int> ans (ll.size());  //initialize with 0

        for(int i=0 ; i<ll.size() ; i++){
            while(!st.empty() && ll[i] > ll[st.top()]){
                int kid = st.top();
                st.pop();
                ans[kid] = ll[i];
            }
            st.push(i);
        }
        return ans;
    }
};