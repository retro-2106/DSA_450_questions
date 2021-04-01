class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
       if(S.empty())
       return S;
       
       if(S.length() == 1)
       return S;
       
       if(S[0] == S[1])
       {
           S = S.substr(1);
           return removeConsecutiveCharacter(S);
       }
       else
       {
           return S[0] + removeConsecutiveCharacter(S.substr(1));
       }
    }
};