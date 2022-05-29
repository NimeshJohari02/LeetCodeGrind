class Solution {
public:
    vector<int> bits;
    void helper(vector<string>&words){
        for(auto &word : words){
            int ans = 0 ;
            for(auto &ch : word)
                ans = ans | 1<<(ch-'a');
            bits.push_back(ans);
        }
        return ;
    }
    int maxProduct(vector<string>& words) {
        helper(words);
        int ans = 0;
        for(int i=0 ; i< words.size() ; i++){
            for(int j = i+1 ; j < words.size() ; j++){
                if((bits[i] & bits[j])==0){
                    int maxi = words[i].length() * words[j].length();
                    ans = max( ans ,  maxi );
                }
            }
        }
        return ans;
    }
};