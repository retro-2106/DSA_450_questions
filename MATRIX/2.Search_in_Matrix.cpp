class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size() == 0)
           return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if(m != 0)
        {
            n = matrix[0].size();
        }
        else
        {
            n =0;
        }
        int low = 0,high = m*n-1;
        if(high == 0)
           return matrix[0][0] == target;
        int mid,x,y;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            x = mid/n;
            y = mid%n;
            
            if(matrix[x][y] == target)
            {
                return true;
            }
            else
            {
                matrix[x][y] > target? high = mid-1:low = mid+1;
            }
            
        }
        return false;
    }
};
