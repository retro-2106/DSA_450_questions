int height(Node *root)
{
    if(!root)
    return 0;
    
    return 1 + max(height(root->left),height(root->right));
}

bool isBalanced(Node *root)
{
    if(!root)
    return true;
    
    if(abs(height(root->left)-height(root->right))>1)
    return false;
    
    if(!isBalanced(root->left))
    return false;
    if(!isBalanced(root->right))
    return false;
    
    return true;
}