class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>LIS(nums.size() , 1);
        for(int i =1 ; i<nums.size() ; i++){
            int currMax =0;
            for(int j = i-1 ; j>=0 ; j--){
                if(nums[i]>nums[j]){
                    currMax = max(currMax , LIS[j]);
                }
            }
            LIS[i] = 1+currMax;
        }
        // for(auto it : LIS)
        //     cout<<it<<"   ";
        // cout<<endl;
        vector<int>LDS(nums.size() , 1);
        for(int i=nums.size()-1 ; i >=0 ; i--){
            int cm =0;
            for(int j= nums.size() -1 ; j>i ; j--){
                if(nums[i]>nums[j]){
                    cm = max(cm , LDS[j]);
                }
            }
            LDS[i]= 1+cm;
        }
        int correctPos=0;
        for(int i=0 ; i< nums.size() ; i++){
            if(LIS[i]>1 and LDS[i]>1){
                correctPos = max(correctPos, LIS[i]+LDS[i]-1);
            }
        }
        return nums.size() - correctPos;
    }
};

