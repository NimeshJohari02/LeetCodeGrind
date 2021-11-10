class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int buyIdx =0;
        //  The idea is to buy at local min and dont sell till next element is larger than currPrice . This way 
        /*
           /s\      /s\    /(s)
          /   \    /   \  /
        b/     \b /     \b
        even if you have something like this  you can buy and sell plus add the last case . ie after the end of the loop 
        add 
         currProfit+=(prices[sellIdx]-prices[buyIdx]);
        because just in case there is no dip at the last just like above given figure then that part will not be included 
        if there is a dip then the val would be zero hence no over counts .
        */
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
