class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
            return root;
        
        TreeNode *left,*right;
        left = invertTree(root->left);
        right = invertTree(root->right);
        root->left = right;
        root->right = left;
        
        return root;
    }
};