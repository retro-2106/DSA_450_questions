int getvalue(char ch)
{
    if(ch == 'I')
    return 1;
    
    if(ch == 'V')
    return 5;
    
    if(ch == 'X')
    return 10;
    
    if(ch == 'L')
    return 50;
    
    if(ch == 'C')
    return 100;
    
    if(ch == 'D')
    return 500;
    
    if(ch == 'M')
    return 1000;
    
    return -1;
}
int romanToDecimal(string &str) 
{
    int n = str.length();
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(i < n-1 && getvalue(str[i+1]) > getvalue(str[i]))
        {
            ans -= getvalue(str[i]);
        }
        else
        {
            ans += getvalue(str[i]);
        }
    }
    
    return ans;
}