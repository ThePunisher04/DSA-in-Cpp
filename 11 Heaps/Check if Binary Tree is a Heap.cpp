// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

// Example 1:

// Input:
//       5
//     /  \
//    2    3
// Output: 1
// Explanation: The given tree follows max-heap property since 5,
// is root and it is greater than both its children.

class Solution {
  public:
    int nodeCount(struct Node* root){
        if(!root) return 0;
        int l = nodeCount(root->left);
        int r = nodeCount(root->right);
        return 1 + l + r;
    }
    
    bool isCBT(struct Node* root, int i, int& n){
        if(!root) return true;
        if(i > n) return false;
        
        return isCBT(root->left, 2*i, n) && isCBT(root->right, 2*i + 1, n);
    }
    
    bool isMaxOrder(struct Node* root){
        if(!root) return true;
        bool l = isMaxOrder(root->left);
        bool r = isMaxOrder(root->right);
        bool ans = false;
        if(!root->left && !root->right){
            //leaf node
            ans = true; 
        }
        else if(root->left &&!root->right){
            //only left child exists
            ans = root->data > root->left->data;
        }
        else{
            //both children exist
            ans = (root->data > root->left->data) && (root->data > root->right->data);
        }
        return ans && l && r;
    }
  
    bool isHeap(struct Node* tree) {
        // code here
        int n = nodeCount(tree);
        int i=1;
        return isCBT(tree, i, n) && isMaxOrder(tree);    }
};