vector<int> topView(struct Node *root)
{
    vector<int> ans;
    if(!root)
    return ans;
    
    queue<pair<Node*,int>> qu;
    map<int,int> m;
    
    qu.push(make_pair(root,0));
    
    while(!qu.empty())
    {
        pair<Node*,int> front;
        
        front = qu.front();
        qu.pop();
        
        if(m[front.second] == 0)
        {
            m[front.second] = front.first->data;
        }
        
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