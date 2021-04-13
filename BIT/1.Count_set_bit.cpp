class Solution {
  public:
    int setBits(int N) 
    {
        int count = 0;
        for(int i=0;i < sizeof(N)*8;i++)
        {
            if(N & 1<<i)
            {
                count++;
            }
        }
        
        return count;
    }
};
