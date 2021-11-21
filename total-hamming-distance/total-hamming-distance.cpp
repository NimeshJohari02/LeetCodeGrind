class Solution {
public:

int totalHammingDistance(vector<int>& nums) {
    int ans =0;
    for(int i =0 ; i <32 ; i++){
        int count=0;
        for(int j=0 ; j<nums.size();j++){
            count+=(nums[j]>>i) &1 ; // to check whether the ith bit is set or not if yes increase the count as it becomes
            // candidate to contribute to the hamming distance ie  k*(n-k) where k is the number of elements that have that bit set in our case denoted by count variable;
        }
        ans+=count*(nums.size()-count);
    }
return ans;
}
        
};