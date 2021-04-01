#include <bits/stdc++.h>
using namespace std;

int search(vector<int> nums, int target) 
    {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r)
        {
            int mid = (r-l)/2 +l;
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < nums[r])
            {
                if(nums[mid] < target && target <=nums[r])
                l = mid + 1;
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                if(nums[l] <=target && target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
        }
        return -1;
    }

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> input;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            input.push_back(a);
        }
        int k;
        cin>>k;
        
        cout<<search(input,k)<<endl;
    }
	return 0;
}