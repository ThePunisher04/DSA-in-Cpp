class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;
        int robThisHouse = 0, dontRobThisHouse = 0;

        //rob current house
        robThisHouse += root->val;

        if(root->left){
            robThisHouse += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right){
            robThisHouse += solve(root->right->left) + solve(root->right->right);
        }

        //dont rob current house
        dontRobThisHouse += solve(root->left) + solve(root->right);

        return max(robThisHouse, dontRobThisHouse);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};




class Solution {
public:
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root) return 0;
        if(dp.find(root) != dp.end()) return dp[root];
        int robThisHouse = 0, dontRobThisHouse = 0;

        //rob current house
        robThisHouse += root->val;

        if(root->left){
            robThisHouse += solve(root->left->left, dp) + solve(root->left->right, dp);
        }
        if(root->right){
            robThisHouse += solve(root->right->left, dp) + solve(root->right->right, dp);
        }

        //dont rob current house
        dontRobThisHouse += solve(root->left, dp) + solve(root->right, dp);

        dp[root] = max(robThisHouse, dontRobThisHouse);
        return dp[root];
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solve(root, dp);
    }
};