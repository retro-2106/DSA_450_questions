vector <int> bottomView(Node *root)
{
    vector<int> ans;
   if(!root)
   return ans;
   
   queue<pair<Node*,int>> qu;
   
   qu.push(make_pair(root,0));
   map<int,int> m;
   
   while(!qu.empty())
   {
       pair<Node*,int>front = qu.front();
       qu.pop();
       
       m[front.second] = front.first->data;
       
       if(front.first->left)
       {
           qu.push(make_pair(front.first->left,front.second-1));
       }
       if(front.first->right)
       {
           qu.push(make_pair(front.first->right,front.second+1));
       }
   }
   
   for(auto it=m.begin();it != m.end();it++)
   {
       ans.push_back(it->second);
   }
   return ans;
}