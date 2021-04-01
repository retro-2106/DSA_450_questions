Node *temp;
int ans;

Node *helper(Node *root,int &k,int node)
{
    if(!root)
    return NULL;
    
    if(root->data == node ||
    (temp = helper(root->left,k,node))||
    (temp = helper(root->right,k,node)))
    {
        if(k > 0)
        k--;
        else if(k == 0)
        {
            ans = root->data;
            return NULL;
        }
        return root;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    temp = NULL;
    ans = -1;
    if(helper(root,k,node))
    return -1;
    
    return ans;
}