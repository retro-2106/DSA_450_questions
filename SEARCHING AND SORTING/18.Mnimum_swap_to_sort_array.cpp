int minSwaps(vector<int>&nums)
	{
	   pair<int,int> arr[nums.size()];
	   
	   for(int i=0;i<nums.size();i++)
	   {
	       arr[i].first = nums[i];
	       arr[i].second = i;
	   }
	   
	   sort(arr,arr+nums.size());
	   
	   vector<bool>  visited(nums.size(),false);
	   int ans=0;
	   
	   for(int i=0;i<nums.size();i++)
	   {
	       if(visited[i] || arr[i].second == i)
	       continue;
	       int cycles = 0;
	       int j = i;
	       while(!visited[j])
	       {
	           visited[j] = 1;
	           
	           j = arr[j].second;
	           
	           cycles++;
	       }
	       
	       if(cycles > 0)
	       {
	           ans += (cycles - 1);
	       }
	   }
	   
	   return ans;
	}
