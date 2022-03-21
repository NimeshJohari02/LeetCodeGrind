class Solution {
public:
    // last occurance of each letter;
    vector<int> partitionLabels(string s) {
        unordered_map<char , int> lastOcc;
        for(int i=0 ; i < s.size() ; i++){
            lastOcc[s[i]] = i+1;
        }
        vector<int> res ;
        for(int i = 0 ; i <s.size(); i++) {
            int lastIdx  = lastOcc[s[i]];
            int count = 0; 
            for(int j = i; j < lastIdx ; j++) {
                lastIdx = max(lastIdx, lastOcc[s[j]]);
                count++;
            }
            res.push_back(count);
            i = lastIdx-1;
        }
        return res; 
    }
};