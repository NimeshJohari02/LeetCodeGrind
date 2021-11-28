class Solution {
vector<int> arr; 
public:
Solution(vector<int> nums) {
    arr= nums;
}

int pick(int target) {
    int n = 0, ans = -1;
    for(int i = 0 ; i < arr.size(); i++){
        if(arr[i] != target) continue;
        if(n == 0){ans = i; n++;}
        else{
            n++;
            if(rand() % n == 0){ans = i;}// with prob 1/(n+1) to replace the previous index
        }
    }
    return ans;
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */