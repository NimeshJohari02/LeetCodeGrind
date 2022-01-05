class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>mp;
        int ans =0;
                          
       for(auto x:time){
            ans+=mp[(60 - x % 60) % 60];
            mp[x%60]++;
        }
        return ans;
    }
};