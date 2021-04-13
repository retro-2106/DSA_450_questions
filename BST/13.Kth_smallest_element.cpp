void inorder(Node *root,int K,vector<int> &v)
{
    if(root == NULL)
    return;
    
    inorder(root->left,K,v);
    
    v.push_back(root->data);
    
    inorder(root->right,K,v);
}

int KthSmallestElement(Node *root, int K)
{
    vector<int> v;
    inorder(root,K,v);

    if(K > v.size())
    return -1;
    
    return v[K-1];
}
