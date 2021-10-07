class Solution {
public:
    int ans=0,DONE;
    void solve(int rowMask,int ld , int rd){
        if(rowMask==DONE){ans++;return;}
        int safe = DONE &(~(rowMask|ld|rd));
        int safe2 = INT_MAX &(~(rowMask|ld|rd));
        // cout<<safe<<"   "<<safe2<<endl;
        while(safe){
            int p = safe & (-safe);
            safe = safe-p;
            solve(rowMask|p,(ld|p)<<1,(rd|p)>>1);
        }
    }
    int totalNQueens(int n) {
        DONE=(1<<n)-1;
        solve(0,0,0);
        return ans;
    }
};