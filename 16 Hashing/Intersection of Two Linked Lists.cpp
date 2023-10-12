// Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

// Example 1:

// Input:
// LinkedList1: 9->6->4->2->3->8
// LinkedList2: 1->2->8->6
// Output: 6 2 8

//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        unordered_map<int, int> map;
        Node* curr = head2;
        //hash L2 items
        while(curr){
            map[curr->data]++;
            curr = curr->next;
        }
        
        Node* IL = 0;
        Node* it = 0;
        curr = head1;
        
        while(curr){
            if(map.find(curr->data) != map.end()){
                //node val found in L2
                if(!IL){
                    IL = curr;
                    it = IL;
                }
                else{
                    if(map[curr->data] > 0){
                        it->next = curr;
                        it=it->next;
                        map[curr->data]--;
                    }
                }
            }
            curr=curr->next;
        }
        it->next=0;
        return IL;
    }
};

