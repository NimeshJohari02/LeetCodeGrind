class Solution {
public:
    int dp[10001];
    int numSquares(int n ){
       /* dp[0]=0;
        vector<int>sq;
        dp[1]=1;
        sq.push_back(1);
        for(int i=2;i<=n;i++){
            
            if(ceil(sqrt(i))==floor(sqrt(i))){
                dp[i]=1;
                sq.push_back(i);
            }
            else{
                // int prevSquare= pow(floor(sqrt(i)),2);
                int currMin = INT_MAX;
                for(int j =0;j<sq.size();j++){
                    int candidate = dp[i-sq[j]]+dp[sq[j]];
                    currMin= min(currMin,candidate);
                }
                dp[i]=currMin;
            }
        }
     return dp[n];   */
        //The second approach is taken from the comments section it used 
        //https://en.wikipedia.org/wiki/Lagrange's_identity_(disambiguation)
            while (n % 4 == 0)
        n /= 4;
    if (n % 8 == 7)
        return 4;
    int a = -1, b = sqrt(n);
    n -= b * b;
    b += b + 1;
    while (a <= b) {
        if (n < 0)
            n += b -= 2;
        else if (n > 0)
            n -= a += 2;
        else
            return a < 0 ? 1 : 2;
    }
    return 3;
    }
};