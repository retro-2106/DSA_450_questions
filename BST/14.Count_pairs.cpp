bool search(Node *root,int x)
{
    if(root == NULL)
    return false;
    
    if(root->data == x)
    return true;
    
    if(x < root->data)
    return search(root->left,x);
    else
    return search(root->right,x);
}


int countPairs(Node* root1, Node* root2, int x)
{
    int cnt=0;
    if(root1 == NULL || root2 == NULL)
    return cnt;
    int a = root1->data;
    
    if(search(root2,(x-a)))
    {
        cnt++;
    }
    
    int left = countPairs(root1->left,root2,x);
    int right = countPairs(root1->right,root2,x);
    
    return left + right + cnt;
}
