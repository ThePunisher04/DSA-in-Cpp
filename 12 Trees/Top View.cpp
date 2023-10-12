
void printTopView(Node* root) {
        if(root == NULL )
                return;
        
        ///create a map for storing HD -> TopNode ->data
        map<int, int> topNode;

        //Level Order
        //we will store a pair consisting of Node and Horizontal Distance
        queue< pair<Node*, int> > q;
        q.push(make_pair(root, 0));

        while(!q.empty()) {
                pair<Node*, int> temp = q.front();
                q.pop();

                Node* frontNode = temp.first;
                int hd = temp.second;

                //jo bhi horizontal distance aaya h , check if answer for that hd already exists
                //or not
			
                if(topNode.find(hd) == topNode.end()) {
                        //crete entry
                        topNode[hd] = frontNode->data;
                }

                if(frontNode -> left)
                        q.push(make_pair(frontNode->left, hd-1));

                if(frontNode -> right)
                        q.push(make_pair(frontNode->right, hd+1));
        }

        //ab aapka answer store hua hoga aapke map me 
        cout << "Printing the answer: " << endl;
        for(auto i: topNode) {
                cout << i.first << " -> " << i.second << endl;
        }
}