class Solution
{
   public:
    int ans;
    void inorder(Node *root,int K,int &c)
    {
        if(root == NULL|| c >= K)
        return;
        inorder(root->right,K,c);
        
        c++;
        if(c == K)
        {
            ans = root->data;
            return;
        }
        
        inorder(root->left,K,c);
    }
    
    int kthLargest(Node *root, int K)
    {
        int c = 0;
        ans = 0;
        inorder(root,K,c);
        return ans;
    }
};
