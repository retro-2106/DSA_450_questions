int sum(Node *root)
{
    if(root == NULL)
    return 0;
    
    
    return root->data + sum(root->left) + sum(root->right);
}

bool isSumTree(Node* root)
{
     if(root == NULL)
     return true;
     
     if(root->left == NULL && root->right == NULL)
     return true;
     
     int left  = sum(root->left);
     int right = sum(root->right);
     
     if(root->data == left + right && isSumTree(root->left)
     && isSumTree(root->right))
     return true;
     
     
     return false;
}