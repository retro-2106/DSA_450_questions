class Solution {
    public:
    int knows(vector<vector<int>> &M,int i,int j)
    {
        return M[i][j];
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
      int a = 0;
    int b = n - 1;
    while (a < b)
    {
        if (knows(M,a, b))
            a++;
        else
            b--;
    }

    for (int i = 0; i < n; i++)
    {
        if ( (i != a) &&
                (knows(M,a, i) || 
                !knows(M,i, a)) )
            return -1;
    }
 
    return a;
    }
};