vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    if(!root)
    return ans;
    
    stack<Node*> s1,s2;
    s1.push(root);
    bool l2r = true;
    
    while(!s1.empty())
    {
        Node* front = s1.top();
        s1.pop();
        
        ans.push_back(front->data);
        
        if(l2r)
        {
            if(front->left)
            {
                s2.push(front->left);
            }
            if(front->right)
            {
                s2.push(front->right);
            }
        }
        else
        {
            if(front->right)
            {
                s2.push(front->right);
            }
            if(front->left)
            {
                s2.push(front->left);
            }
        }
        
        if(s1.empty())
        {
            l2r = !l2r;
        swap(s1,s2);
        }
        
    }
    return ans;
}