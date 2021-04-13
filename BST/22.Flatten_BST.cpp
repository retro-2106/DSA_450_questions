void inorder(node* curr, node*& prev)
{
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

node* flatten(node* parent)
{
    // Dummy node
    node* dummy = new node(-1);
    node* prev = dummy;
    inorder(parent, prev);
  
    prev->left = NULL;
    prev->right = NULL;
    node* ret = dummy->right;

    delete dummy;
    return ret;
}
