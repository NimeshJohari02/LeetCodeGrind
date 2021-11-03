class Solution {
public:
    static bool cmp(pair<int,int>p1 , pair <int,int>p2){
        if(p1.second==p2.second){
            return p1.first>p2.first;
        }
        return p1.second<p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        nums.clear();
        vector<pair<int,int>>mpArr;
        for(auto it : mp){
            mpArr.push_back({it.first,it.second});
        }
        sort(mpArr.begin(),mpArr.end(),cmp);
        for(auto it : mpArr){
           vector<int>miniAns(it.second,it.first);
            nums.insert(nums.end(),miniAns.begin(),miniAns.end());
        }
        return nums;
    }
};