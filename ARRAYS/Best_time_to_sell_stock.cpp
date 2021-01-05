class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minindex = 0;
        int maxprofit = 0;
        
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i] < prices[minindex])
            {
                minindex = i;
            }
            
            int cp = prices[i] - prices[minindex];
            if(cp > maxprofit)
            {
                maxprofit = cp;
            }
        }
        return maxprofit;
    }
};