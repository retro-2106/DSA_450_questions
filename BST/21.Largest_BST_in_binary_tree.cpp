struct info
{
    int sub_size;
    int max_value;
    int min_value;
    int size;
    bool isBst;
};

info helper(Node *root)
{
    if(root == NULL)
    {
        return {0,INT_MIN,INT_MAX,0,true};
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        return {1,root->data,root->data,1,true};
    }
    
    info left = helper(root->left);
    info right = helper(root->right);
    
    info ans;
    
    ans.sub_size = 1 + left.sub_size + right.sub_size;
    
    if(left.isBst && right.isBst && left.max_value < root->data && right.min_value > root->data)
    {
        ans.min_value = min(root->data,min(left.min_value,right.min_value));
        ans.max_value = max(root->data,max(left.max_value,right.max_value));
        
        
        ans.size = ans.sub_size;
        ans.isBst = true;
        
        return ans;
    }
    
    ans.size = max(left.size,right.size);
    ans.isBst = false;
    return ans;
}
int largestBst(Node *root)
{
    if(root == NULL)
    return 0;
    
    return helper(root).size;
}
