typedef long long int ll;
class Solution {
public:
    vector<bool> canEat(vector<int>& cc, vector<vector<int>>& queries) {
        vector<bool> res; 
        vector<ll> maxAllowed(cc.size(),0);
        maxAllowed[0]=cc[0];
        for(int it =1 ; it<cc.size();it++){
            maxAllowed[it]+=maxAllowed[it-1]+cc[it];
        }
        
        for(auto it : queries) {
           int ft = it[0];
            int fd = it[1];
            int cap = it[2];
             if(ft==0){
                bool val = fd<maxAllowed[ft]?true:false;
                res.push_back(val);
                continue;
            }
            long long int earliest = maxAllowed[ft-1]/cap;
            long long int latest = maxAllowed[ft]-1;

            if(earliest<=fd && fd<=latest) 
            {
                res.push_back(true);
            }
            else 
            {
                res.push_back(false);
            }
        }

        return res; 
    }
};