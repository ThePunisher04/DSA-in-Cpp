//LC-938

// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int ans=0;

        bool wasInRange = false;
        if(root->val >= low && root->val <= high){
            wasInRange = true;
            ans += root->val;
        }
        if(wasInRange){
            ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        else if(root->val < low){
            ans += rangeSumBST(root->right, low, high);
        }
        else if(root->val > high){
            ans += rangeSumBST(root->left, low, high);
        }

        return ans;
    }
};