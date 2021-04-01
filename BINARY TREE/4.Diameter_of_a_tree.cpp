int height(struct Node* node)
{
     if(!node)
    return 0;
        
    return 1 + max(height(node->left),height(node->right));
}
int diameter(Node* root) 
{
   if(!root)
   return 1;
   
   return max(1 + height(root->left) + height(root->right),
   max(diameter(root->left),diameter(root->right)));
}