Node *LCA(Node *root,int n1,int n2)
{
    if (root == NULL)
       return root;
    if (root->data == n1 || root->data == n2)
       return root;
 
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
 
    if (left != NULL && right != NULL)
         return root;
    if (left == NULL && right == NULL)
           return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);
 
    return LCA(root->right, n1, n2);
}

int distance(Node *root,int k,int level)
{
     if(root == NULL) return -1;
    if(root->data == k) return level;
 
    int left = distance(root->left, k, level+1);
   if (left == -1)
       return distance(root->right, k, level+1);
    return left;
}

int findDist(Node* root, int a, int b) 
{
    if(root == NULL)
    return 0;
    Node *lca = LCA(root,a,b);
    
    int x = distance(lca,a,0);
    int y = distance(lca,b,0);
    
    return x+y;
}