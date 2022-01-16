class Solution {
public:
int maxDistToClosest(vector<int> arr) {
        int res = 0;
    int n = arr.size();
        int i = -1;
        for (int j = 0; j < n; ++j) {
            if (arr[j] == 1) {
                res = i < 0 ? j : max(res, (j - i) / 2);
                i = j;
            }
        }
        res = max(res, n - i - 1);
        return res;
    }
};