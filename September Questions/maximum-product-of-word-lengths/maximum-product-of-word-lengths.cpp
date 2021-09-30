class Solution {
public:
    vector<int>bitRep;
    void converstNumsToBits(vector<string> &words){
        for(auto it:words){
            int ans=0;
            for(auto i : it){
              ans = ans | (1<<(i-'a'));
            }
            bitRep.push_back(ans);
        }
        return;
    }
    int max(int a , int b){
        return a>b?a:b;
    }
    int maxProduct(vector<string>& words) {
        int maximum = 0;
        converstNumsToBits(words);
        for(int i=0;i<bitRep.size()-1;i++){
            for(int j=i+1;j<bitRep.size();j++){
                if((bitRep[j]&bitRep[i])==0){
                    maximum = max(maximum,(words[i].length()*words[j].length()));
                }
            }
        }
        return maximum;
    }
};