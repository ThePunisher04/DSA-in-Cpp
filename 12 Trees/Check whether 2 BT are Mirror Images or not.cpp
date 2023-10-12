class Solution {
public:
    bool isMirror(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        else if(p==NULL || q==NULL){
            return 0;
        }
        else{
            bool op1 = p->val == q->val;
            bool op2 = isMirror(p->left, q->right);
            bool op3 = isMirror(p->right, q->left);

            if(op1 && op2 && op3){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};