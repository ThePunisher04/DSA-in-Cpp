vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   if(!root){
       return ans;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       Node* temp = q.front(); q.pop();
       while(temp){
           ans.push_back(temp->data);
           if(temp->left){
               //baad mein dekh lenge
               q.push(temp->left);
           }
           temp = temp->right;
       }
   }
   return ans;
}