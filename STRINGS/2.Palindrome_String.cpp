class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    int left = 0;
	    int right = S.length()-1;
	    
	    while(left < right)
	    {
	        if(S[left] != S[right])
	        return 0;
	        
	        left++;
	        right--;
	    }
	    
	    return 1;
	}

};