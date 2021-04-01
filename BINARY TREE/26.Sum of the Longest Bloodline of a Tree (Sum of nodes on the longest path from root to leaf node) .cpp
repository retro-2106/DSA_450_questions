
void helper(Node* root,int sum,int len,int &maxlen,int &maxsum)
{
    if(!root)
    {
        if(maxlen < len)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if(maxlen == len && maxsum < sum)
        maxsum = sum;
        
        return;
    }
    
    helper(root->left,sum + root->data,len+1,maxlen,maxsum);
    
    helper(root->right,sum + root->data,len + 1,maxlen,maxsum);
}

int sumOfLongRootToLeafPath(Node* root)
{
	if(root == NULL)
	return 0;
	int max_sum = INT_MIN,max_len=0;
	helper(root,0,0,max_len,max_sum);
	
	return max_sum;
}