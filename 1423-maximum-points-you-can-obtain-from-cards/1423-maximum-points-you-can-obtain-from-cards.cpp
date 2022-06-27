// class Solution {
// public:
//   int maxScore(vector<int>& nums, int k) {
//         int total = accumulate(nums.begin() , nums.end() , 0);
//         if(k==nums.size())return total;
//         int cs = accumulate(nums.begin() , nums.end()-k , 0);
//         int ans = total - cs;
//         for(int i=0 , j = nums.size() - k; j < nums.size() ; j++ , i++){
//             ans=max(ans ,  total - (cs += nums[j]-nums[i]));
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int i =0 , j =0 , cs = 0 ;
        int total = accumulate(nums.begin() , nums.end() , 0);
        if(k==nums.size())return total;
        int minWindowSum = INT_MAX;
        k=nums.size()-k;
        for(int j=0 ; j < nums.size() ; j++){
        cs+=nums[j];
             if(j-i+1 > k){
                cs-=nums[i++];
                minWindowSum = min(minWindowSum , cs);
            }
            if(j-i+1 == k){
                minWindowSum = min(minWindowSum , cs);
            }
           
        }
        cout<<minWindowSum<<"\n Total = "<<total<<"\n";
        return total-minWindowSum;
    }
};