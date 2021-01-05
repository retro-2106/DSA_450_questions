class Solution {
public:
    
   static bool compare(vector<int> a,vector<int> b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size() == 0)
            return intervals;
        sort(intervals.begin(),intervals.end(),compare);
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(res.back()[1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};