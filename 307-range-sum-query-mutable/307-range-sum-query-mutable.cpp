class SGTree {
  vector<int> seg;

 public:
  void resizeTree(int n) { seg.resize(4 * n + 1); }
  void build(int idx, int low, int high, vector<int>& arr) {
    if (low == high) {
      seg[idx] = arr[low];
      return;
    }
    int mid = (low + high) >> 1;
    build(2 * idx + 1, low, mid, arr);
    build(2 * idx + 2, mid + 1, high, arr);
    seg[idx] = (seg[2 * idx + 1]+ seg[2 * idx + 2]);
  }
  // LR are the given query params
  int query(int idx, int low, int high, int l, int r) {
    // No Overlap
    if (low > r || high < l) return 0;
    if (low >= l && high <= r) return seg[idx];
    int mid = (low + high) >> 1;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return (left+ right);
  }
  //  here i , val are given as params to update the ith element to val
  void update(int idx, int low, int high, int i, int val) {
    if (low == high) {
      seg[idx] = val;
      return;
    }
    int mid = (low + high) >> 1;
    if (i <= mid)
      update(2 * idx + 1, low, mid, i, val);
    else
      update(2 * idx + 2, mid + 1, high, i, val);
    seg[idx] = (seg[2 * idx + 1]+ seg[2 * idx + 2]);
  }
};

class NumArray {
    private :
    int n;
    SGTree segtree;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resizeTree(n);
        segtree.build(0 , 0 , n-1 , nums);
    }
    void update(int index, int val) {
        segtree.update(0 , 0 ,n-1 , index , val);
    }
    
    int sumRange(int l, int r) {
        return segtree.query(0 ,0, n-1 , l , r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */