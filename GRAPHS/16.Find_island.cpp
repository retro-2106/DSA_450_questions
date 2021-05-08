class Solution
{
    public:
    //Function to find the number of islands.

    int isSafe(vector<vector<char>>& grid, int row, int col, bool visited[][1000])
{
    return (row >= 0) && (row < grid.size()) && (col >= 0) && (col < grid[0].size()) 
    && (grid[row][col] == '1' && !visited[row][col]);
}
    void dfs(vector<vector<char>>& M, int row, int col,bool visited[][1000])
    {
        static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    visited[row][col] = true;

    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            dfs(M, row + rowNbr[k], col + colNbr[k], visited);
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        bool visited[1000][1000];
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};