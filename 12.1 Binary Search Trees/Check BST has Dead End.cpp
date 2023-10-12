// Given a Binary Search Tree that contains positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

void isDeadEndHelper(Node* root, unordered_map<int, bool>& visited, bool& ans){
    if(root==0) return;
    //visit the node
    visited[root->data] = 1;
    if(root->left == 0 && root->right == 0){
        //leaf node
        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;
        if(visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()){
            ans=true;
            return;
        }
    }
    isDeadEndHelper(root->left, visited, ans);
    isDeadEndHelper(root->right, visited, ans);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    bool ans = false;
    unordered_map<int, bool> visited;
    isDeadEndHelper(root, visited, ans);
    return ans;
}