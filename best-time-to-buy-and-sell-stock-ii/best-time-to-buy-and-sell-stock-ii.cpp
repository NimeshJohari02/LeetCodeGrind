class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int buyIdx =0;
        int sellIdx =0;
        int currProfit =0;
        for(int i =1 ; i < prices.size() ; i++){
            if(prices[i]>=prices[i-1]){
                sellIdx++;
            }
            else{
                currProfit+=(prices[sellIdx]-prices[buyIdx]);
                sellIdx=buyIdx=i;
            }
        }
         currProfit+=(prices[sellIdx]-prices[buyIdx]);
        return currProfit;
    }
};