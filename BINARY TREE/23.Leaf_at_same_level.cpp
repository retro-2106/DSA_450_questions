int leaf_level;
bool helper(Node *root,int level)
{
    if(root == NULL)
    return true;
    
    if(root->left == NULL && root->right == NULL)
    {
        if(leaf_level == 0)
        {
            leaf_level = level;
            return true;
        }
        
        return leaf_level == level;
    }
    
    return helper(root->left,level+1) && helper(root->right,level+1);
}

bool check(Node *root)
{
    int level = 0;
   leaf_level = 0;
    
    return helper(root,level);
}