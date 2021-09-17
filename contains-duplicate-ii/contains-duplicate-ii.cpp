class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      map<int,int>mp;
      for(int i=0;i<nums.size();i++)
      {
        cout<<"nums[i]"<<nums[i]<<"  i "<<i<<endl;
        if(mp[nums[i]]!=i+1 and mp[nums[i]]!=0){
            cout<<"Nums i -> "<<nums[i]<<"i = "<<i<<"MP"<<mp[nums[i]]<<endl;
            if(abs(i+1-mp[nums[i]])<=k){
              return true;
            }
        }
        // else{
        mp[nums[i]]=i+1;
      // }
      }
      return false;
    }
};