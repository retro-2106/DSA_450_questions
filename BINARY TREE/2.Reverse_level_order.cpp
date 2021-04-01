vector<int> reverseLevelOrder(Node *root)
{
   queue<Node*> qu;
   vector<int> ans;
   qu.push(root);
   stack<int> stk;
   while(!qu.empty())
   {
       Node *front = qu.front();
       qu.pop();
       stk.push(front->data);
      
       if(front->right)
       qu.push(front->right);
       if(front->left)
       qu.push(front->left);
   }
   while(!stk.empty())
   {
       ans.push_back(stk.top());
       stk.pop();
   }
   return ans;
}
