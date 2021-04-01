vector<int> levelOrder(Node* root)
{
  vector<int> ans;
  queue<Node *> qu;
  
  qu.push(root);
  while(!qu.empty())
  {
      int n = qu.size();
      
      for(int i=0;i<n;i++)
      {
          Node *front = qu.front();
          qu.pop();
          ans.push_back(front->data);
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
