class Solution {
  public:
    int countSquares(int N) 
    {
       return (floor(sqrt(N-1)) - ceil(sqrt(1)) + 1); 
    }
};