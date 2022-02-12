class Solution {
public:
    // Brute Force is N^2 to check all the pairs
    // Optimal Is To use mergeSort
    //!!NOTE TO AVOID RUNTIME ERROR AT CASE
    //[2147483647,2147483647,2147483647,2147483647,2147483647,2147483647] 
    //TYPECAST TO LL 
    int merge(vector<int>&nums , int low , int mid , int high){
        int count =0;
        int j = mid+1;
        for(int i=low ; i <=mid ;i++){
            while(j <=high && nums[i] > 2LL * nums[j])
                j++;
            count+=(j-(mid+1));
        }
        
        // sort parts routine
        vector<int>temp;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <=high)
        {
            if(nums[left]<=nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        while(left<=mid)
                temp.push_back(nums[left++]);
        while(right<=high)
                temp.push_back(nums[right++]);
        for(int i=low ; i <=high ; i++)
            nums[i] = temp[i-low];
        return count;
    }
    int mergesort(vector<int>&nums , int low , int high){
        if (low>=high)return 0;
        int mid = (low + high)/2;
        int ans = mergesort(nums , low , mid);
         ans += mergesort(nums, mid+1 , high);
        ans+=merge(nums , low , mid , high);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0 , nums.size()-1);
    }
};