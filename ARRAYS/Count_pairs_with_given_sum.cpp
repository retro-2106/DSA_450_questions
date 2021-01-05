class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
        unordered_map<int,int> ispresent;
        
        for(int i=0;i<n;i++)
        {
            ispresent[arr[i]]++;
        }
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            count += ispresent[k - arr[i]];
            
            if(arr[i] + arr[i] == k)
            count--;
        }
        
        return count/2;
    }
};