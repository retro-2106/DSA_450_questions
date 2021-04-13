Node *root;
Node* insert_helper(Node *root,int data)
{
    if(root == NULL)
    {
        root = newNode(data);
        return root;
    }
    
    if(root->data > data)
    {
        root->left = insert_helper(root->left,data);
    }
    else
    {
        root->right = insert_helper(root->right,data);
    }
    return root;
}
void insert(int data)
{
    root = insert_helper(root,data);
}
Node* constructTree(int pre[], int size) 
{
    root = NULL;
    for(int i=0;i<size;i++)
    {
        insert(pre[i]);
    }
 return root;   
}
