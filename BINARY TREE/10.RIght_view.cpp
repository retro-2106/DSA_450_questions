ector<int> rightView(Node *root)
{
    vector<int> ans;
   if(!root)
   return ans;
   
   queue<Node*> qu;
   qu.push(root);
   
   while(!qu.empty())
   {
       int n = qu.size();
       
       for(int i=1;i<=n;i++)
       {
           if(i == n)
           {
               ans.push_back(qu.front()->data);
           }
           
           Node *front = qu.front();
           qu.pop();
           if(front->left)
           {
               qu.push(front->left);
           }
           
           if(front->right)
           {
               qu.push(front->right);
           }
       }
   }
   return ans;
}