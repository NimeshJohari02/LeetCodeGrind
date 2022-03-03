class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int ans = 0, cur = 0, cb = 0, a = 0, b = 0;
        for (int c :  fruits) {
            cur = (c == a) || (c == b) ? cur + 1 : cb + 1;
            cb = (c == b) ? cb + 1 : 1;
            if (b != c) a = b;
            b = c;
            ans = max(ans, cur);
        }
        return ans;
    }
};