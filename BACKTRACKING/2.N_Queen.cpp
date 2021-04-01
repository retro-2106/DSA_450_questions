class Solution{
public:

    vector<vector<int>> board;
    int row[10];
    bool place(int r,int c) {
    	for(int prev=0;prev<c;prev++)
    		if(row[prev]==r or abs(row[prev]-r)==abs(prev-c))
    			return false;
    	return true;
    }
    void solve(int c,int n)
    {
        if(n == 2 || n == 3)
        return;
        
        if(c == n)
        {
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                v.push_back(row[i]+1);
            }
             board.push_back(v);
        }
        for(int i=0;i<n;i++)
        {
            if(place(i,c))
            {
                row[c] = i;
                solve(c+1,n);
            }
        }
        
    }
    
    vector<vector<int>> nQueen(int n) 
    {
        
        board.clear();
        solve(0,n);
        return board;
    }
};