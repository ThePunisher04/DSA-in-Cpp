int solve(Node* root){
    if(root == NULL)
        return 0;

    int leftSum = solve(root->left);
    int rightSum = solve(root->right);
    int val = root->data;

    root->data = leftSum + root->data + rightSum ;

    return root->data;
}

void toSumTree(Node* node){
    solve(node);
}