class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>hashMap;
        if(s.length()<10){
            return {};
        }
        for(int i=0;i<=s.length()-9;i++){
            string currDna="";
            for(int j=i;j<i+10;j++){
                currDna+=s[j];
            }
            hashMap[currDna]++;
        }
        vector<string>ans;
        for(auto x:hashMap){
            if(x.second>1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};