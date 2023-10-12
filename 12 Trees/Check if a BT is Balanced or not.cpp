//LC-110

class Solution {
public:
    int height(TreeNode* root) {
        //base case
        if(root == NULL)
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int ans = 1 + max(leftHeight, rightHeight);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        //Base case
        if(root == NULL)
            return true;

        //1 case
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool ans1 = (diff <= 1);

        //Recursion
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(ans1 && leftAns && rightAns)
            return true;
        else
            return false;
    }
};


//FASTER METHOD

class Solution{
    public:

    bool isBalanced = true;

    int height(TreeNode* root){
        if(!root) return 0;

        int l_height = height(root->left);
        int r_height = height(root->right);

        //check for current node, is it balanced ?
        if(isBalanced && abs(l_height - r_height) > 1){
            isBalanced = false;
        }

        return max(l_height, r_height) + 1;
    }

    bool isBalanced(TreeNode* root){
        height(root);
        return isBalanced;
    }
};