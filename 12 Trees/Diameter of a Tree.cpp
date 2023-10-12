
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) 
		return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) 
        return 0;

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + 1 + maxDepth(root->right);
        int ans = max(op1, max(op2, op3));
        return ans ;
    }


};


//FASTER METHOD

class Solution{
    public:

    int diameter = 0;

    int height(TreeNode* root){
        if(!root) return 0;

        int l_height = height(root->left);
        int r_height = height(root->right);

        //diameter calculate
        int currDiameter = l_height + r_height;
        diameter = max(diameter, currDiameter);

        return max(l_height, r_height) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root){
        height(root);
        return diameter;
    }
};