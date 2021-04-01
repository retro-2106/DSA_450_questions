class Solution
{
public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {
        unordered_map<int,int> mapp;
        
        for(int i=0;i<n;i++)
        {
            mapp[arr[i]]++;
        }
        
        for(auto it: mapp)
        {
            if(it.second > n/2)
            {
                return it.first;
            }
        }
        return -1;
    }
};