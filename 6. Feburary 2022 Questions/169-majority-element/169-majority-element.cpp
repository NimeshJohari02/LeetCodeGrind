class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = -1;
        int cnt = 0;
        for(auto &it : nums) {
            if(cnt == 0) {
                num = it;
                cnt = 1;
            } else if(num == it) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return num;
    }
};