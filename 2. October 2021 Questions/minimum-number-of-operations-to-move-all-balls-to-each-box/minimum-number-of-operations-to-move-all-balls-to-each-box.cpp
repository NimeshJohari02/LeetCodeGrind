class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>OneIdx;
        for(int i =0 ; i<boxes.length();i++){
            if(boxes[i]=='1'){
                OneIdx.push_back(i);
            }
        }
        vector<int>res;
        for(int i =0 ; i<boxes.size();i++){
        int ans =0;
            for(auto it : OneIdx){
                ans += abs(it-i);
            }
        res.push_back(ans);
            ans=0;
            }
        return res;
    }
};