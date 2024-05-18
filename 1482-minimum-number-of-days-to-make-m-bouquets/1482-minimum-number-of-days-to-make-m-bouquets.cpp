class Solution {
public:
    bool canMakeMBouquets(int currNumberOfDays , vector<int>&bloomDay , int m , int k){
        int consecutiveFlowersBloomed=0 ;
        int currentNumberOfBouqets = 0 ;
        for(int i=0 ; i < bloomDay.size() ; i++){
            if(currNumberOfDays>=bloomDay[i]) consecutiveFlowersBloomed++;
            else {
                currentNumberOfBouqets += (consecutiveFlowersBloomed / k);
                consecutiveFlowersBloomed = 0 ;
            }
        }
    //ending ;
        currentNumberOfBouqets += (consecutiveFlowersBloomed / k);
        return currentNumberOfBouqets>= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int start = 1 ;
        long long int  end = *max_element(bloomDay.begin() , bloomDay.end());
        long long int ans = end ;
        bool flag = false ;
        while(end>=start){
            long long int mid = start + (end - start) / 2 ;
            if(canMakeMBouquets(mid , bloomDay , m , k)){
                flag = true;
                ans = min(ans , mid);
                end = mid-1 ;
            }
            else start = mid+1;
        }
        return flag ? ans : -1  ;
    }
};