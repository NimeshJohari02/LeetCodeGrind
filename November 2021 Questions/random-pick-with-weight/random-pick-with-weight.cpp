class Solution {
public:
    vector<int> pre;
    Solution(vector<int>& w) {
        pre.push_back(w[0]);
        for(int i = 1; i < w.size(); i++) {
            pre.push_back(w[i]+pre.back());
        }
    }

    int pickIndex() {
        int num = pre.back();
        int idx = rand()%num; 
        auto it = upper_bound(pre.begin(), pre.end(), idx);
        return it - pre.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */ 
