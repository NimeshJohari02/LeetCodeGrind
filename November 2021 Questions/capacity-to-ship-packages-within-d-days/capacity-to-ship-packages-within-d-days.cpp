class Solution {
public:
    bool isPossible(vector<int>weights, int days , int maxWeight){
        int sum =0;
        int count =1;
        for(auto it : weights){
            if(it > maxWeight){
                return false;
            }
            if(sum+it > maxWeight){
                count++;
                sum =it;
            }
            else{
                sum+=it;
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high=0;
        for(auto it : weights){
            high+=it;
        }
        int ans = high;
        while(high >= low){
            int mid = (low + high)/2;
            if(isPossible(weights,days,mid)){
                ans = mid ;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};