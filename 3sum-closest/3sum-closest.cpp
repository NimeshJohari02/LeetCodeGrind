class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int nearestSum = INT_MAX;
        int globalResidue=0;
        for(int i=0;i<nums.size();i++){
            // target-=nums[i];
            int front = i+1;
            int back = nums.size()-1;
            while(back>front){
            int sum = nums[i]+nums[front]+nums[back];
                cout<<"Sum "<<sum<<endl;
                cout<<" Target "<<target<<endl;
            if(sum>target){
                if((sum-target)<nearestSum){
                    nearestSum = sum-target;
                    globalResidue = sum;
                }
                back--;
           } 
            else  if(sum<target){
                if((target-sum)<nearestSum){
                    nearestSum = target-sum;
                    globalResidue = sum;
                }
                front++;
            }
            else {
                return sum;
            }
           }
        }
        return globalResidue;
    }
};