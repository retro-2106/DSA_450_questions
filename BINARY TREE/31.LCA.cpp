class Solution
{
    public:
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL)
       return  root;
       
       if(root->data == n1)
       return root;
       if(root->data == n2)
       return root;
       
       Node *left = lca(root->left,n1,n2);
       Node *right = lca(root->right,n1,n2);
       
       if(left != NULL && right == NULL)
       return left;
       
       if(left == NULL && right != NULL)
       return right;
       
       if(left == NULL && right == NULL)
       return NULL;
       
       return root;
    }
};