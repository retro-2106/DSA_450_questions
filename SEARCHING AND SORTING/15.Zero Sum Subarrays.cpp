ll findSubarray(vector<ll> arr, int n ) 
{
    unordered_map<ll,ll> mapp;
    ll sum = 0;
    ll count=0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        
        if(sum == 0)
        {
            count++;
        }
        
        if(mapp.count(sum) != 0)
        {
            count+= mapp[sum];
        }
        mapp[sum]++;
    }
    return count;
}