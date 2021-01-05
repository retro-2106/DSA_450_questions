int getMinDiff(int arr[], int n, int k) 
    {
        sort(arr,arr+n);
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;
        
        int ans = arr[n-1] - arr[0];
        
        if(smallest > largest)
        swap(smallest,largest);
        
        
        for(int i=1;i<n;i++)
        {
            int add = arr[i] + k;
            int sub = arr[i] - k;
            
            if(sub >= smallest || add <= largest)
            continue;
            
            if(largest - sub <= add - smallest)
            {
                smallest = sub;
            }
            else
            {
                largest = add;
            }
        }
        return min(ans,largest - smallest);
    }