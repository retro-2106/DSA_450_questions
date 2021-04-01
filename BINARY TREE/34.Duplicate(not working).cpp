vector<int> ans;
string inorder(Node *node, unordered_map<string,int> &m)
{
    if(!node)
    return "$";
    
    string left = inorder(node->left,m);
    string right = inorder(node->right,m);
    
    string str = to_string(node->data) + "$" + left + "$" + right;
    
    if(m[str] == 1)
    ans.push_back(node->data);
    
    m[str]++;
    return str;
}

void printAllDups(Node* root)
{
    ans.clear();
    unordered_map<string,int> m;
    inorder(root,m);
    if(ans.size() ==0)
    cout<<"-1";
    else
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}