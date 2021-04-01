int helper(Node *root)
{
    if(!root)
   return 0;
   
   int old_value = root->data;
   
   root->data = helper(root->left) + helper(root->right);
   
   return old_value + root->data;
}
void toSumTree(Node *root)
{
   int a = helper(root);
}
