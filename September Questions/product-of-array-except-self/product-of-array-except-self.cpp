class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),0) ;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ans[i]=1;
            }else
            {
            ans[i]=ans[i-1]*nums[i-1];
            }
        }
        for(auto it : ans){cout<<it<<"   ";}
        cout<<endl;
        int fromRight=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i==(nums.size()-1)){
                ans[i]=ans[i]*1;
            }
            else
            {
                fromRight=fromRight*nums[i+1];
                cout<<"From Right"<<fromRight<<endl;
            ans[i]=ans[i]*fromRight;
            }
        }
        return ans;
    }
};