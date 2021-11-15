class Solution {
public:
    static bool cmp(string x , string y)
    {
        if(x.length()==y.length()){
            int i=0;
            while(x[i]==y[i] and i<min(x.length(),y.length())){
                i++;
            }
            return x[i]>y[i];
        }
        return x.length()>y.length();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        for(auto it:nums){
            cout<<it<<"  ";
       } 
        cout<<endl;
        return nums[k-1];
    }
};