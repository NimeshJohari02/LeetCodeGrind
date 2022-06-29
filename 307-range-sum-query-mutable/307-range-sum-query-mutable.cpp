class BIT{
    vector<int>arr ;
    int n ;
    public:
    BIT(){}
    BIT(int _n){
        n = _n;
        arr = vector<int>(_n+1 , 0);
    }
    void buildBIT(vector<int>&ip){
        for(int i=0 ; i <n ; i++)
            update(i+1 , ip[i]);
    }
    int sum(int idx){
        int ans = 0 ;
        for(; idx>0 ; idx-=(idx &(-idx)))
            ans += arr[idx];
        return ans; 
    }
    void update(int idx , int val){
        for(;idx<=n ; idx+=(idx&(-idx)))
            arr[idx] += val;
    }
};


class NumArray {
public:
    BIT bit;
    vector<int>arr;
    NumArray(vector<int>& nums) {
        bit = BIT(nums.size());
        bit.buildBIT(nums);
        arr = nums;
    }
    void update(int index, int val) {
        bit.update(index+1, val - arr[index]);   
        arr[index]=val;
    }
    
    int sumRange(int left, int right) {
        return bit.sum(right+1) - bit.sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */