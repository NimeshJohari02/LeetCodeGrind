class Solution {
public:
    void nextPermutation(vector<int>& num) {
         for(int i = num.size() - 2; i >= 0; i--){
        if(num[i] < num[i + 1]){
            int pos;
            int diff = INT_MAX;
            for(int j = i + 1; j < num.size(); j++){
                if(num[j] > num[i] && abs(num[i] - num[j]) < diff){
                    diff = abs(num[i] - num[j]);
                    pos = j;
                }
            }
            swap(num[i], num[pos]);
            sort(num.begin() + i + 1, num.end());
            return;
        }
    }
    sort(num.begin(), num.end());
    }
};