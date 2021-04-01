class Solution
{
    public:
    Node* prev = NULL;
    bool isBST(Node* root) 
    {
        if(root == NULL)
        return true;
        
        if(isBST(root->left) == false)
        return false;
        
        if(prev != NULL)
        {
            if(prev->data >= root->data)
            return false;
        }
        prev = root;
        return isBST(root->right);
        
    }
};
