class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int currentOneExtraStock  = -prices[0];
        int currentNoExtraStock  = 0;
        for(int  i =1 ; i<prices.size(); i++){
            int newOneExtraStock =0 ;
            int newNoExtraStock =0 ;
            if(currentNoExtraStock - prices[i]  > currentOneExtraStock){
                newOneExtraStock= currentNoExtraStock - prices[i];
            }else{
                newOneExtraStock = currentOneExtraStock;
            }
            if(currentOneExtraStock + prices[i] - fee >  currentNoExtraStock){
             newNoExtraStock =     currentOneExtraStock + prices[i] - fee;
            }
            else{
                newNoExtraStock = currentNoExtraStock;
            }
            currentOneExtraStock= newOneExtraStock;
            currentNoExtraStock=newNoExtraStock;
        }
        return currentNoExtraStock;
    }
};