class Solution {
public:
    vector<int> ans;
    void dfs(int start , int end){
        if (start > end) return;
        ans.push_back(start);
        dfs(start * 10, end);
        if (start % 10 != 9) dfs(start+1, end);

    }
    vector<int> lexicalOrder(int n) {
        dfs(1 , n );
        return ans ;
    }
};