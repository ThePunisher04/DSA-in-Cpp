
void printRightView(Node* root, vector<int> &ans, int level) {
	//base case
	if(root == NULL) 
		return;

	if(level == ans.size()) {
		ans.push_back(root->data);
	}

	//right
	printRightView(root->right, ans, level+1);

	//left
	printRightView(root->left, ans, level+1);
}
