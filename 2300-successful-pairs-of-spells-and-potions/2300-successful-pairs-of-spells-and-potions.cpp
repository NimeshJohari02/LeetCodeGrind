class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       //sort potions
        sort(potions.begin() , potions.end());
        vector<int>ans;
        for(int i=0 ; i < spells.size() ; i++){
            long long  needed = ceil(success*1.0 / spells[i]);
            auto it = lower_bound(potions.begin() , potions.end() , needed);
            ans.push_back(potions.end() - it) ;
        }
        return ans;
    }
};