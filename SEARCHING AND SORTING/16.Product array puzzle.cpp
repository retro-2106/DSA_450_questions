vector<long long int> productExceptSelf(vector<long long int>& arr, int n) 
{
   vector<long long int> left(n,1),right(n,1);
   
   left[0] = 1;
   for(int i=1;i<n;i++)
   {
       left[i] = left[i-1]*arr[i-1];
   }
   right[n-1] = 1;
   for(int i=n-2;i>=0;i--)
   {
       right[i] = right[i+1]*arr[i+1];
   }
   
   vector<long long int> ans(n,1);
   for(int i=0;i<n;i++)
   {
       ans[i] = left[i]*right[i];
   }
   
   return ans;
}