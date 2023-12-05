class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuyingPrice = prices[0] , maximumProfit = 0;
        for(auto& it :prices){
            minBuyingPrice = min(minBuyingPrice , it);
            maximumProfit = max(maximumProfit , it-minBuyingPrice);
        }
        return maximumProfit;
    }
};