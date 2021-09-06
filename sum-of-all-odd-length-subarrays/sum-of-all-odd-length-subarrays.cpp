class Solution {
public:
  // Refer To This For Explaination https://www.geeksforgeeks.org/count-of-contiguous-subarrays-possible-for-every-index-by-including-the-element-at-that-index/
    int sumOddLengthSubarrays(vector<int>& arr) {
      int currSum=0;
      for(int i=0;i<arr.size();i++){ 
      int sum =0;
        for(int j=i;j<arr.size();j++){
          sum+=arr[j];
          if((j-i)%2==0){
            currSum+=(sum);
          }
      }
    }
        return currSum;
    }
};