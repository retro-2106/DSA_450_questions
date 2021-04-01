//leetcode

class Solution {
public:
    string minWindow(string s, string t) 
    {
        string result;
        if(s.empty() || t.empty())
            return result;
        
        unordered_map<char,int> mapp;
        unordered_map<char,int> window;
        
        for(int i=0;i<t.length();i++)
        {
            mapp[t[i]]++;
        }
        
        int minlength = INT_MAX;
        int lettercount = 0;
        
        for(int slow=0,fast=0;fast < s.length();fast++)
        {
            char c = s[fast];
            if(mapp.find(c) != mapp.end())
            {
                window[c]++;
                if(window[c] <= mapp[c])
                {
                    lettercount++;
                }
            }
            
            if(lettercount >= t.length())
            {
                while(mapp.find(s[slow]) == mapp.end() || window[s[slow]] > mapp[s[slow]])
                {
                    window[s[slow]]--;
                    slow++;
                }
                
                if(fast - slow +1 < minlength)
                {
                    minlength = fast-slow +1;
                    result = s.substr(slow,fast-slow+1);
                }
            }
        }
        return result;
    }
};