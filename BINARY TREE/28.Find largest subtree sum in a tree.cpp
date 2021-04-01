int findLargestSubtreeSumUtil(Node* root, int& ans) 
{  
    if (root == NULL)      
        return 0; 
 
    int currSum = root->key +  
      findLargestSubtreeSumUtil(root->left, ans) 
      + findLargestSubtreeSumUtil(root->right, ans); 

    ans = max(ans, currSum); 
    return currSum; 
} 
   
int findLargestSubtreeSum(Node* root) 
{ 
    if (root == NULL)      
        return 0; 
      
    int ans = INT_MIN; 
    findLargestSubtreeSumUtil(root, ans); 
  
    return ans; 
} 