vector<int> leftView(Node *root)
{
  queue<Node*> qu;
  qu.push(root);
  
  vector<int> ans;
  if(!root)
  return ans;
  
  while(!qu.empty())
  {
      int n = qu.size();
      
      for(int i=1;i<=n;i++)
      {
          if(i == 1)
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