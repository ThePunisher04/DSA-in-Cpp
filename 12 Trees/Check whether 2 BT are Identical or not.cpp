class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        else if(p==NULL || q==NULL){
            return 0;
        }
        else{
            bool op1 = p->val == q->val;
            bool op2 = isSameTree(p->left, q->left);
            bool op3 = isSameTree(p->right, q->right);

            if(op1 && op2 && op3){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
};