// Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

// Example 1:

// Input:
//              10
//           /      \
//         -2        6
//        /   \     /  \
//      8     -4   7    5

// Output:
//             20
//           /    \
//         4        12
//        /  \     /  \
//      0     0   0    0


class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int sum(Node* root){
        if(!root) return 0;
        
        int temp = root->data;
        if(!root->left && !root->right){
            //leaf node
            temp = root->data;
            root->data = 0;
            return temp;
        }
        
        int l_sum = sum(root->left);
        int r_sum = sum(root->right);
        
        root->data = l_sum + r_sum;
        return root->data + temp;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }
};