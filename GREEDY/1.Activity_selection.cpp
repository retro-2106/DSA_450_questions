bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n) 
{
    int count = 1;
    
    vector<pair<int,int>> input;
    for(int i=0;i<n;i++)
    {
        input.push_back(make_pair(start[i],end[i]));
    }
    
    sort(input.begin(),input.end(),compare);
    
    vector<pair<int,int>> ans;
    
    ans.push_back(input[0]);
    
    for(int i=1;i<n;i++)
    {
        if(input[i].first > ans.back().second)
        {
            ans.push_back(input[i]);
            count++;
        }
    }
    return count;
}