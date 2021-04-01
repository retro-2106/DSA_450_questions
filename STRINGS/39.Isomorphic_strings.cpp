#include<bits/stdc++.h>
bool areIsomorphic(string str1, string str2)
{
    if(str1.size() != str2.size())
    return false;
    unordered_map<char,char> mapp;
    
    set<char> seen;
    
    for(int i=0;i<str1.length();i++)
    {
        if(mapp.find(str1[i]) != mapp.end())
        {
            if(mapp[str1[i]] != str2[i])
            return false;
        }
        else
        {
            if(seen.count(str2[i]) >  0)
            return false;
            
            mapp[str1[i]] = str2[i];
            seen.insert(str2[i]);
        }
    }
    return true;
}