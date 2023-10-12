class Solution{
  public:
    // returns the inorder predecessor of the Node x in BST (rooted at 'root')
    Node * inOrderPredecessor(Node *root, Node *x)
    {
        //Your code here
        Node * pred = 0;
        Node * curr = root;
        
        while(curr){
            if(curr->data < x->data){
                pred = curr;
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        
        return pred;
    }
};