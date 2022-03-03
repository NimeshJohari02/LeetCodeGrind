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

//Another Approach is to use binary search Along with LCS to enable a finer Time Complexity 



class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), m;
        vector<int> lis, lds; lis.resize(n); lds.resize(n);
        int *candidate = new int[n];
        
        lis[0] = 1; candidate[0] = nums[0]; m = 1;
        // Reducing the Typical LIS from n2 to nlogn . As mountain is asked thus parts need to be increasing in order when looking uphill and decreasing when going reverse.
        for(int i=1;i<n;i++) {
            int j = lower_bound(candidate, candidate + m, nums[i]) - candidate;
            candidate[j] = nums[i];
            m = max(m, j+1);
            lis[i] = j+1;
        }
        
        lds[n-1] = 1; candidate[0] = nums[n-1]; m = 1;
        for(int i=n-2;i>=0;i--) {
            int j = lower_bound(candidate, candidate + m, nums[i]) - candidate;
            candidate[j] = nums[i];
            m = max(m, j+1);
            lds[i] = j+1;
        }
        
        m = 1;
        for(int i=1;i<n-1;i++) if( lis[i]!=1 && lds[i]!=1 )
            m = max(m, lis[i] + lds[i] - 1);
        return n-m;
    }
};

