class Solution {
public:
        int maxProfit(vector<int>& prices)
    {
        int mp=INT32_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mp)
            {
                mp=prices[i];
            }
            else if (prices[i]-mp>profit)
            {
                profit=prices[i]-mp;
            }
        }
        return profit;
        
    }
};