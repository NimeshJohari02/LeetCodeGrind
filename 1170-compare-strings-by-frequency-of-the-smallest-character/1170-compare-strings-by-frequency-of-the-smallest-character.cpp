class Solution {
public:
    int freq(string& word){
        int minChar = INT_MAX ;
        for(auto &it : word)
            minChar = min(minChar , it-'a');
        int frequency = 0 ;
        for(auto &it : word)
            if(it == minChar+'a') frequency++;
        return frequency ; 
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>freqArr(12 , 0);
        vector<int>ans;
        // Every Frequency word will contribute 1 to it's previous frequencies ;
        for(auto &word : words){
            for(int i = freq(word) ; i >=1  ; i--){
                freqArr[i]++;
            }
        }
        for(auto &it : freqArr) cout<<it<<" ";
        cout<<"\n";
//      1 <= queries[i].length, words[i].length <= 10
        for(auto &word : queries){
            ans.push_back(freqArr[freq(word)+1]);
        }
        return ans ; 
    }
};