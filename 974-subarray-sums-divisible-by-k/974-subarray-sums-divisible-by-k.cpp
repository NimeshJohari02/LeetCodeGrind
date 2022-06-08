class Solution {

    public:
    int subarraysDivByK(vector<int>& arr, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (auto &it : arr) {
            prefix = (prefix + it % k + k) % k;
            res += count[prefix]++;
        }
        return res;
    }
};