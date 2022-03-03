class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        for(auto it : text){
            mp[it]++;
        }
        string balloon="balloon";
        char minChar='b';
        int minimum = INT_MAX;
        for(auto i : balloon){
            if(mp[i]<minimum){
                minimum = mp[i];
                minChar= i;
            }
        }
        for(int i=minimum;i>0;i--)
        {
            if(mp['l']>=2*i and mp['o']>=2*i){
                return i;
            }
        }
            return 0;
    }
};