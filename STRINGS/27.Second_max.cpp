class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> mapp;
        
        for(int i=0;i<n;i++)
        {
            mapp[arr[i]]++;
        }
        
        int max_value=INT_MIN,sec_max=-1;
        
        for(auto it : mapp)
        {
            if(it.second > max_value)
            {
                sec_max = max_value;
                max_value = it.second;
            }
            else
            {
                if(it.second > sec_max && sec_max != max_value)
                {
                    sec_max = it.second;
                }
            }
        }
        
        for(auto it : mapp)
        {
            if(it.second == sec_max)
            {
                return it.first;
            }
        }
    }
};