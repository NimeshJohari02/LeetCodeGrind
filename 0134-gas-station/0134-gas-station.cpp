class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // We are able to use greedy as the soln is said to be unique. 
        int n = gas.size(), currentFuel = 0, totalCost=0, totalGas = 0 ;
        int ans = 0 ;
        for(int i=0 ; i < n ;i++){
            totalCost+=cost[i];
            totalGas += gas[i];
            currentFuel+=gas[i];
            currentFuel-=cost[i];
            if(currentFuel<0){
                currentFuel = 0 ;
                ans = i+1 ;
            }
        }
        return (totalGas>=totalCost) ? ans : -1 ;
    }
};