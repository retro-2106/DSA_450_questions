class Solution{
public:
	void merge(int a1[], int a2[], int m, int n) 
	{
	   /* for(int i=n-1;i>=0;i--)
	    {
	        int j;
	        int last = a1[m-1];
	        
	        for(j = m-2;j>=0 && (a1[j] > a2[i]); j--)
	        {
	            a1[j+1] = a1[j];
	        }
	        
	        if(j != m-2 || last > a2[i])
	        {
	            a1[j+1] = a2[i];
	            a2[i] = last;
	        }
	    }*/
	    int j = 0, i = m-1;
while(j < n && i > -1 && a2[j] < a1[i])
swap(a2[j++],a1[i--]);
sort(a1,a1+m);
sort(a2,a2+n);

	    
	}
};