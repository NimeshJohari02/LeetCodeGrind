class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int maximumPositiveSum =0;
        int currentSum =0;
       for(auto &it : nums){
           currentSum +=it;
           if(currentSum <0 )
               currentSum=0; 
           maximumPositiveSum = max(currentSum , maximumPositiveSum );
       }
        currentSum =0;
       int minimumPositiveSum =0; 
        for(auto&it : nums){
           currentSum +=it;
           if(currentSum >=0 )
               currentSum=0; 
           minimumPositiveSum = min(currentSum , minimumPositiveSum );
        }
    return max(abs(minimumPositiveSum ), maximumPositiveSum);
    }
};