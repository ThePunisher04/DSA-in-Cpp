// Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

// Example 1:

// Input:
// L1 = 9->6->4->2->3->8
// L2 = 1->2->8->6->2
// Output: 
// 1 2 3 4 6 8 9
// Explaination: 
// All the distinct numbers from two lists, when sorted forms the list in the output. 



class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        map<int, Node*> map;
        
        Node* curr = head1;
        //L1 hashed 
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        
        curr = head2;
        //L2 hashed 
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        
        Node* UL = nullptr;
        curr = 0;
        for(auto it : map){
            if(!UL){
                UL = it.second;
                curr = UL;
            }
            curr->next = it.second;
            curr = curr->next;
        }
        //for the last node
        curr->next = 0;
        return UL;
    }
};





