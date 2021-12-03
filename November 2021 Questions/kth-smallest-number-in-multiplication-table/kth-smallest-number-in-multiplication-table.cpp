class Solution {
public:
    bool kislessthanMid(int m , int n , int mid , int k){
                    int c = 0;
        for (int i = 1; i <= m; i++)
            c += min(n, mid/i);
        
        return c >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int left=1;
        int right = m*n;
        if(k==left || k==right){
            return k;
        }
        while(right>left){
            int mid = (left + right)/2;
            if(kislessthanMid(m , n , mid , k)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        cout<<left<<" -> "<<right<<"  ";
        return (left);
    }
};