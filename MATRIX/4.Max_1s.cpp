class Solution{
public:

int findindex(vector<int> a,int s,int e)
{
    
    int ans=-1;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        if((mid == 0 || a[mid-1] == 0) && a[mid]==1)
        {
            ans = mid;
            break;
        }
        
        else if(a[mid] == 0)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return ans;
}
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
	{
	    int max_row_index=-1,max=-1;
	    for(int i=0;i<n;i++)
	    {
	        int index = findindex(arr[i],0,m-1);
	        if(index != -1 && m-index > max)
	        {
	            max = m- index;
	            max_row_index = i;
	        }
	    }
	    
	    return max_row_index;
	}

};