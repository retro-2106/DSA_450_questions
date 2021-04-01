vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    map<string,vector<string>> mapp;
    
    for(int i=0;i<string_list.size();i++)
    {
        string temp = string_list[i];
        sort(temp.begin(),temp.end());
        
        mapp[temp].push_back(string_list[i]);
    }
    
    vector<vector<string>> ans;
    
    for(auto it = mapp.begin();it != mapp.end();it++)
    {
        vector<string> temp = it->second;
        ans.push_back(temp);
    }
    
    return ans;
}